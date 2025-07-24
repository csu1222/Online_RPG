#include "pch.h"
#include "Room.h"
#include "Player.h"
#include "Monster.h"
#include "GameSession.h"
#include "Utils.h"

RoomRef GRoom = make_shared<Room>();

Room::Room()
{
	// 룸 생성시 타이머를 시작한다.
	ULONGLONG tick = GetTickCount64();
	_nowTickCount = static_cast<float>(tick);
	_beforeTickCount = _nowTickCount;
}

Room::~Room()
{
}

bool Room::EnterRoom(ObjectRef object, bool randPos)
{
	bool success = AddObject(object);

	// 랜덤 위치
	if (randPos)
		SetRandomPosition(object);

	// 입장 사실을 신입 플레이어에게 알린다

	if (object->IsPlayer())
		BroadcastToEnteredPlayers(object, success);
	if (object->IsMonster())
		BroadcastToSpawnedMonsters();

	return success;
}

bool Room::LeaveRoom(ObjectRef object)
{
	if (object == nullptr)
		return false;

	const uint64 objectId = object->objectInfo->object_id();
	bool success = RemoveObject(objectId);

	// 퇴장 사실을 퇴장하는 플레이어에게 알린다
	if (auto player = dynamic_pointer_cast<Player>(object))
	{
		Protocol::S_LEAVE_GAME leaveGamePkt;
		leaveGamePkt.set_object_id(objectId);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(leaveGamePkt);
		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}

	// 퇴장 사실을 알린다
	{
		Protocol::S_DESPAWN despawnPkt;
		despawnPkt.add_object_ids(objectId);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(despawnPkt);
		Broadcast(sendBuffer, objectId);

		if (auto player = dynamic_pointer_cast<Player>(object))
			if (auto session = player->session.lock())
				session->Send(sendBuffer);
	}

	return success;
}

bool Room::HandleEnterPlayer(PlayerRef player)
{
	return EnterRoom(player, true);
}

bool Room::HandleLeavePlayer(PlayerRef player)
{
	return LeaveRoom(player);
}

void Room::HandleMove(Protocol::C_MOVE pkt)
{

	const uint64 objectId = pkt.info().object_id();

	if (_objects.find(objectId) == _objects.end())
		return;
	
	// 적용
	ObjectRef player = _objects[objectId];
	player->posInfo->CopyFrom(pkt.info());

	// 이동
	{
		Protocol::S_MOVE movePkt;
		{
			Protocol::PosInfo* info = movePkt.mutable_info();
			info->CopyFrom(pkt.info());
		}

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(movePkt);
		Broadcast(sendBuffer);
	}
}

bool Room::HandleSpawnMonster(MonsterRef monster)
{
	// 몬스터가 룸에 들어온다
	_monsterCountAtomic.fetch_add(1);

	return EnterRoom(monster, true);
}

bool Room::HandleDespawnMonster(MonsterRef monster)
{
	// 몬스터가 룸에서 나간다
	_monsterCountAtomic.fetch_sub(1);

	return LeaveRoom(monster);
}

void Room::UpdateTick()
{
	// TODO : 룸 업데이트 로직

	// 몬스터 스폰 타이머 업데이트
	_beforeTickCount = _nowTickCount;
	ULONGLONG tick = GetTickCount64();
	_nowTickCount = static_cast<float>(tick);

	float deltaTime = (_nowTickCount - _beforeTickCount) / 1000.f; // 초 단위로 변환

	// 몬스터 스폰 업데이트
	DoAsync(&Room::UpdateSpawnMonser, deltaTime);

	// 0.1 초 마다 다시 업데이트
	DoTimer(100, &Room::UpdateTick);
}

void Room::UpdateSpawnMonser(float deltaTime)
{
	_spawnTimer -= deltaTime;

	if (_spawnTimer <= 0.0f)
	{
		if (_monsterCountAtomic.load() < MAX_MONSTER_COUNT)
		{
			// 몬스터 스폰
			MonsterRef monster = ObjectUtils::CreateMonster(GetRoomRef());

			if (HandleSpawnMonster(monster))
			{
				string monsterId = Utils::FloatToString(monster->GetData(L"Id"));
				// 몬스터 스폰 성공 로그
				//cout << "Monster Spawned : " << monster->objectInfo->object_id() << endl;
				//cout << "Monster Count : " << _monsterCountAtomic.load() << endl;
			}
			else
			{
				string monsterId = Utils::FloatToString(monster->GetData(L"Id"));
				// 몬스터 스폰 실패 로그
				cout << "Monster Spawn Failed : " << monsterId << endl;
				// TODO : 몬스터 스폰 실패 처리
				_monsterCountAtomic.fetch_sub(1); // 실패시 몬스터 수 감소
			}


			bool RangeCheckResult = CheckMonsterCollision(monster);
			while (true)
			{
				if (RangeCheckResult)
					break; // 충돌이 없으면 루프 종료

				// 충돌이 있으면 새로운 위치를 할당
				SetRandomPosition(monster);
				cout << "Adjusted position for monster " << monster->objectInfo->object_id() << " due to collision." << endl;

				// 다시 충돌 체크
				RangeCheckResult = CheckMonsterCollision(monster);
			}

			// 룸 내의 몬스터들끼리 너무 가까우면 새로운 좌표를 할당
			// 추가 되는 몬스터만 위치가 중첩되는지 체크한다.
			if (_monsters.empty() != true)
			{
				for (auto& findId : _monsters)
					{
						auto iter = _objects.find(findId);
						if (iter == _objects.end())
							continue;

						MonsterRef existingMonster = dynamic_pointer_cast<Monster>(iter->second);
						if (existingMonster == nullptr || existingMonster->objectInfo->object_id() == monster->objectInfo->object_id())
							continue;

						float distance = Utils::CalculateDistance(
							monster->posInfo->x(), monster->posInfo->y(),
							existingMonster->posInfo->x(), existingMonster->posInfo->y()
						);
						if (distance < _monsterCollisionRange)
						{
							SetRandomPosition(monster);
							cout << "Adjusted position for monster " << monster->objectInfo->object_id() << " due to collision." << endl;
						}
					}
			}
		}


		BroadcastToSpawnedMonsters();

		// 타이머 초기화
		_spawnTimer = ROOM_MONSTER_SPAWN_DELAY;

		bool monsterCountValue = CheckMonsterCount();
	}

}

RoomRef Room::GetRoomRef()
{
	return static_pointer_cast<Room>(shared_from_this());
}

bool Room::AddObject(ObjectRef object)
{
	// 있다면 문제가 있다.
	if (_objects.find(object->objectInfo->object_id()) != _objects.end())
		return false;

	_objects.insert(make_pair(object->objectInfo->object_id(), object));

	object->room.store(GetRoomRef());

	// 플레이어인 경우
	if (object->IsPlayer())
		{
			// 있다면 문제가 있다.
			if (_players.find(object->objectInfo->object_id()) != _players.end())
				return false;

			PlayerRef player = dynamic_pointer_cast<Player>(object);
			if (player)
			{
				// 룸에 플레이어 추가
				_players.insert(player->objectInfo->object_id());
			}
	}

	// 몬스터인 경우
	if (object->IsMonster())
	{
		// 있다면 문제가 있다.
		if (_monsters.find(object->objectInfo->object_id()) != _monsters.end())
		{
			cout << "Room::AddObject log : Monster already exists in room." << endl;
			return false;
		}
		MonsterRef monster = dynamic_pointer_cast<Monster>(object);
		if (monster)
		{
			// 룸에 몬스터 추가
			_monsters.insert(monster->objectInfo->object_id());
			auto inserted = _objects.find(monster->objectInfo->object_id()) != _objects.end();
			if (!inserted)
			{
				cout << "Room::AddObject log : Failed to insert monster into room." << endl;
				return false; // 삽입 실패
			}
		}
	}

	return true;
}

bool Room::RemoveObject(uint64 objectId)
{
	// 없다면 문제 없음
	if (_objects.find(objectId) == _objects.end())
		return false;

	ObjectRef object = _objects[objectId];

	if (object->IsCreature())
	{
		CreatureRef creature = dynamic_pointer_cast<Creature>(object);
		if (creature)
		{
			// 룸에서 제거
			creature->room.store(weak_ptr<Room>());
		}
	}

	_objects.erase(objectId);
	_players.erase(objectId);
	_monsters.erase(objectId);

	return true;
}

void Room::SetRandomPosition(ObjectRef object)
{
	object->posInfo->set_x(Utils::GetRandom(0.f, 500.f));
	object->posInfo->set_y(Utils::GetRandom(0.f, 500.f));
	object->posInfo->set_z(100.f);
	object->posInfo->set_yaw(Utils::GetRandom(0.f, 100.f));
}

bool Room::BroadcastToEnteredPlayers(ObjectRef object, bool add_result)
{
	bool result = false;

	// 입장 사실을 신입 플레이어에게 알린다
	if (auto player = dynamic_pointer_cast<Player>(object))
	{
		{
			Protocol::S_ENTER_GAME enterGamePkt;
			enterGamePkt.set_success(add_result);

			Protocol::ObjectInfo* playerInfo = new Protocol::ObjectInfo();
			playerInfo->CopyFrom(*object->objectInfo);
			enterGamePkt.set_allocated_player(playerInfo);

			SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(enterGamePkt);
			if (auto session = player->session.lock())
				session->Send(sendBuffer);
		}
	

		// 입장 사실을 다른 플레이어에게 알린다
		{
			Protocol::S_SPAWN spawnPkt;

			Protocol::ObjectInfo* objectInfo = spawnPkt.add_objects();
			objectInfo->CopyFrom(*object->objectInfo);

			SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(spawnPkt);
			Broadcast(sendBuffer, object->objectInfo->object_id());
		}

		// 기존 입장한 플레이어 목록을 신입 플레이어한테 전송해
		// 준다
		if (auto player = dynamic_pointer_cast<Player>(object))
		{
			Protocol::S_SPAWN spawnPkt;

			for (auto& item : _objects)
			{
				if (item.second->IsPlayer() == false)
					continue;

				Protocol::ObjectInfo* playerInfo = spawnPkt.add_objects();
				playerInfo->CopyFrom(*item.second->objectInfo);
			}

			SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(spawnPkt);
			if (auto session = player->session.lock())
				session->Send(sendBuffer);
		}

		result = true;

		return result;
	}
	return result;
}

bool Room::BroadcastToSpawnedMonsters()
{
	bool result = false;

	if (_monsterCountAtomic.load() <= 0)
		return result;

	if (_monsters.empty())
		return result;

	if(_monsterCountAtomic.load() > MAX_MONSTER_COUNT)
	{
		cout << "Monster Count Exceeded: " << _monsterCountAtomic.load() << endl;
		return result; // 몬스터 수가 최대치를 초과하면 스폰하지 않음
	}

	// 몬스터 스폰 사실을 룸에 있는 플레이어에게 알린다.
	Protocol::S_SPAWN spawnPkt;
	for (auto& pair : _monsters)
	{
		MonsterRef monster = pair.second;
		if (monster == nullptr)
			continue;

		Protocol::ObjectInfo* objectInfo = spawnPkt.add_objects();
		objectInfo->CopyFrom(*monster->objectInfo);
		
		result = true;

		// 스폰할 몬스터의 위치를 로그로 찍는다.
		cout << "Monster Spawned: " << monster->objectInfo->object_id()
			<< " at (" << monster->posInfo->x() << ", "
			<< monster->posInfo->y() << ", "
			<< monster->posInfo->z() << ")" << endl;

	}


	if (result)
	{
		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(spawnPkt);
		Broadcast(sendBuffer);
	}


	return result;
}

bool Room::CheckMonsterCount()
{
	int monsterCount = _monsterCountAtomic.load();
	size_t monstersSize = _monsters.size();

	if (monsterCount != static_cast<int>(monstersSize))
	{
		cout << "[CheckMonsterCount] Mismatch! _monsterCountAtomic: " << monsterCount
			<< ", _monsters.size(): " << monstersSize << endl;
		return false;
	}
	// 일치할 때도 로그를 남기고 싶으면 아래 주석 해제
	// else
	// {
	//     cout << "[CheckMonsterCount] Match: " << monsterCount << endl;
	// }
	return true;
}

bool Room::CheckMonsterCollision(MonsterRef monster)
{
	bool result = false;
	if (_monsters.empty() != true)
	{
		for (auto& pair : _monsters)
		{
			MonsterRef existingMonster = pair.second;
			if (existingMonster == nullptr || existingMonster->objectInfo->object_id() == monster->objectInfo->object_id())
				continue;
			float distance = Utils::CalculateDistance(
				monster->posInfo->x(), monster->posInfo->y(),
				existingMonster->posInfo->x(), existingMonster->posInfo->y()
			);

			// distance가 정상적으로 계산되었는지 확인
			if (distance < 0.0f)
			{
				cout << "Error: Negative distance calculated between monsters." << endl;
				return false; // 거리 계산 오류
			}

			if (distance < _monsterCollisionRange)
			{
				result = false; // 충돌이 발생했으므로 false 반환
				return result; // 충돌이 발생했으므로 false 반환
			}
			else
			{
				result = true; // 충돌이 발생하지 않았으므로 true 반환
				return result; // 충돌이 발생하지 않았으므로 true 반환
			}
		}
	}
	return result;
}

void Room::Broadcast(SendBufferRef sendBuffer, uint64 exceptId)
{
	for (auto& pair : _objects)
	{
		PlayerRef player = dynamic_pointer_cast<Player>(pair.second);
		if (player == nullptr)
			continue;
		if (player->objectInfo->object_id() == exceptId)
			continue;

		if (GameSessionRef session = player->session.lock())
			session->Send(sendBuffer);
	}
}