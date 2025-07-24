#include "pch.h"
#include "Room.h"
#include "Player.h"
#include "Monster.h"
#include "GameSession.h"
#include "Utils.h"

RoomRef GRoom = make_shared<Room>();

Room::Room()
{
	// �� ������ Ÿ�̸Ӹ� �����Ѵ�.
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

	// ���� ��ġ
	if (randPos)
		SetRandomPosition(object);

	// ���� ����� ���� �÷��̾�� �˸���

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

	// ���� ����� �����ϴ� �÷��̾�� �˸���
	if (auto player = dynamic_pointer_cast<Player>(object))
	{
		Protocol::S_LEAVE_GAME leaveGamePkt;
		leaveGamePkt.set_object_id(objectId);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(leaveGamePkt);
		if (auto session = player->session.lock())
			session->Send(sendBuffer);
	}

	// ���� ����� �˸���
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
	
	// ����
	ObjectRef player = _objects[objectId];
	player->posInfo->CopyFrom(pkt.info());

	// �̵�
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
	// ���Ͱ� �뿡 ���´�
	_monsterCountAtomic.fetch_add(1);

	return EnterRoom(monster, true);
}

bool Room::HandleDespawnMonster(MonsterRef monster)
{
	// ���Ͱ� �뿡�� ������
	_monsterCountAtomic.fetch_sub(1);

	return LeaveRoom(monster);
}

void Room::UpdateTick()
{
	// TODO : �� ������Ʈ ����

	// ���� ���� Ÿ�̸� ������Ʈ
	_beforeTickCount = _nowTickCount;
	ULONGLONG tick = GetTickCount64();
	_nowTickCount = static_cast<float>(tick);

	float deltaTime = (_nowTickCount - _beforeTickCount) / 1000.f; // �� ������ ��ȯ

	// ���� ���� ������Ʈ
	DoAsync(&Room::UpdateSpawnMonser, deltaTime);

	// 0.1 �� ���� �ٽ� ������Ʈ
	DoTimer(100, &Room::UpdateTick);
}

void Room::UpdateSpawnMonser(float deltaTime)
{
	_spawnTimer -= deltaTime;

	if (_spawnTimer <= 0.0f)
	{
		if (_monsterCountAtomic.load() < MAX_MONSTER_COUNT)
		{
			// ���� ����
			MonsterRef monster = ObjectUtils::CreateMonster(GetRoomRef());

			if (HandleSpawnMonster(monster))
			{
				string monsterId = Utils::FloatToString(monster->GetData(L"Id"));
				// ���� ���� ���� �α�
				//cout << "Monster Spawned : " << monster->objectInfo->object_id() << endl;
				//cout << "Monster Count : " << _monsterCountAtomic.load() << endl;
			}
			else
			{
				string monsterId = Utils::FloatToString(monster->GetData(L"Id"));
				// ���� ���� ���� �α�
				cout << "Monster Spawn Failed : " << monsterId << endl;
				// TODO : ���� ���� ���� ó��
				_monsterCountAtomic.fetch_sub(1); // ���н� ���� �� ����
			}


			bool RangeCheckResult = CheckMonsterCollision(monster);
			while (true)
			{
				if (RangeCheckResult)
					break; // �浹�� ������ ���� ����

				// �浹�� ������ ���ο� ��ġ�� �Ҵ�
				SetRandomPosition(monster);
				cout << "Adjusted position for monster " << monster->objectInfo->object_id() << " due to collision." << endl;

				// �ٽ� �浹 üũ
				RangeCheckResult = CheckMonsterCollision(monster);
			}

			// �� ���� ���͵鳢�� �ʹ� ������ ���ο� ��ǥ�� �Ҵ�
			// �߰� �Ǵ� ���͸� ��ġ�� ��ø�Ǵ��� üũ�Ѵ�.
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

		// Ÿ�̸� �ʱ�ȭ
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
	// �ִٸ� ������ �ִ�.
	if (_objects.find(object->objectInfo->object_id()) != _objects.end())
		return false;

	_objects.insert(make_pair(object->objectInfo->object_id(), object));

	object->room.store(GetRoomRef());

	// �÷��̾��� ���
	if (object->IsPlayer())
		{
			// �ִٸ� ������ �ִ�.
			if (_players.find(object->objectInfo->object_id()) != _players.end())
				return false;

			PlayerRef player = dynamic_pointer_cast<Player>(object);
			if (player)
			{
				// �뿡 �÷��̾� �߰�
				_players.insert(player->objectInfo->object_id());
			}
	}

	// ������ ���
	if (object->IsMonster())
	{
		// �ִٸ� ������ �ִ�.
		if (_monsters.find(object->objectInfo->object_id()) != _monsters.end())
		{
			cout << "Room::AddObject log : Monster already exists in room." << endl;
			return false;
		}
		MonsterRef monster = dynamic_pointer_cast<Monster>(object);
		if (monster)
		{
			// �뿡 ���� �߰�
			_monsters.insert(monster->objectInfo->object_id());
			auto inserted = _objects.find(monster->objectInfo->object_id()) != _objects.end();
			if (!inserted)
			{
				cout << "Room::AddObject log : Failed to insert monster into room." << endl;
				return false; // ���� ����
			}
		}
	}

	return true;
}

bool Room::RemoveObject(uint64 objectId)
{
	// ���ٸ� ���� ����
	if (_objects.find(objectId) == _objects.end())
		return false;

	ObjectRef object = _objects[objectId];

	if (object->IsCreature())
	{
		CreatureRef creature = dynamic_pointer_cast<Creature>(object);
		if (creature)
		{
			// �뿡�� ����
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

	// ���� ����� ���� �÷��̾�� �˸���
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
	

		// ���� ����� �ٸ� �÷��̾�� �˸���
		{
			Protocol::S_SPAWN spawnPkt;

			Protocol::ObjectInfo* objectInfo = spawnPkt.add_objects();
			objectInfo->CopyFrom(*object->objectInfo);

			SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(spawnPkt);
			Broadcast(sendBuffer, object->objectInfo->object_id());
		}

		// ���� ������ �÷��̾� ����� ���� �÷��̾����� ������
		// �ش�
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
		return result; // ���� ���� �ִ�ġ�� �ʰ��ϸ� �������� ����
	}

	// ���� ���� ����� �뿡 �ִ� �÷��̾�� �˸���.
	Protocol::S_SPAWN spawnPkt;
	for (auto& pair : _monsters)
	{
		MonsterRef monster = pair.second;
		if (monster == nullptr)
			continue;

		Protocol::ObjectInfo* objectInfo = spawnPkt.add_objects();
		objectInfo->CopyFrom(*monster->objectInfo);
		
		result = true;

		// ������ ������ ��ġ�� �α׷� ��´�.
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
	// ��ġ�� ���� �α׸� ����� ������ �Ʒ� �ּ� ����
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

			// distance�� ���������� ���Ǿ����� Ȯ��
			if (distance < 0.0f)
			{
				cout << "Error: Negative distance calculated between monsters." << endl;
				return false; // �Ÿ� ��� ����
			}

			if (distance < _monsterCollisionRange)
			{
				result = false; // �浹�� �߻������Ƿ� false ��ȯ
				return result; // �浹�� �߻������Ƿ� false ��ȯ
			}
			else
			{
				result = true; // �浹�� �߻����� �ʾ����Ƿ� true ��ȯ
				return result; // �浹�� �߻����� �ʾ����Ƿ� true ��ȯ
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