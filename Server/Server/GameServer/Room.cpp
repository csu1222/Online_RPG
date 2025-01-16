#include "pch.h"
#include "Room.h"
#include "Player.h"
#include "GameSession.h"

RoomRef GRoom = make_shared<Room>();

Room::Room()
{
}

Room::~Room()
{
}

bool Room::HandleEnterPlayer(PlayerRef player)
{

	bool success = EnterPlayer(player);

	// ���� ��ġ
	player->playerInfo->set_x(Utils::GetRandom(0.f, 500.f));
	player->playerInfo->set_y(Utils::GetRandom(0.f, 500.f));
	player->playerInfo->set_z(100.f);
	player->playerInfo->set_yaw(Utils::GetRandom(0.f, 100.f));

	// �濡 �����ߴٰ� �˸�
	{
		Protocol::S_ENTER_GAME enterGamePkt;
		enterGamePkt.set_success(success);

		Protocol::PlayerInfo* playerInfo = new Protocol::PlayerInfo();
		playerInfo->CopyFrom(*player->playerInfo);
		enterGamePkt.set_allocated_player(playerInfo);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(enterGamePkt);
		if (auto session = player->ownerSession.lock())
			session->Send(sendBuffer);
	}

	// �濡 �ִ� ��� �÷��̾�� �˸�
	{
		Protocol::S_SPAWN spawnPkt;

		Protocol::PlayerInfo* playerInfo = spawnPkt.add_players();
		playerInfo->CopyFrom(*player->playerInfo);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(spawnPkt);
		Broadcast(sendBuffer, player->playerInfo->object_id());
	}

	// ���� ������ �÷��̾� ����� ���� �÷��̾����� ����
	{
		Protocol::S_SPAWN spawnPkt;
		for (auto& pair : _players)
		{
			PlayerRef otherPlayer = pair.second;
			Protocol::PlayerInfo* playerInfo = spawnPkt.add_players();
			playerInfo->CopyFrom(*otherPlayer->playerInfo);
		}
		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(spawnPkt);
		if (auto session = player->ownerSession.lock())
			session->Send(sendBuffer);
	}
	return success;
}

bool Room::HandleLeavePlayer(PlayerRef player)
{
	if (player == nullptr)
		return false;


	const uint64 objectId = player->playerInfo->object_id();
	bool success = LeavePlayer(objectId);

	// �������� �÷��̾ �˸��� 
	{
		Protocol::S_LEAVE_GAME leaveGamePkt;
		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(leaveGamePkt);
		if (auto session = player->ownerSession.lock())
			session->Send(sendBuffer);
	}

	// �������� �濡 �ִ� ��� �÷��̾�� �˸���
	{
		Protocol::S_DESPAWN despawnPkt;
		despawnPkt.add_object_ids(objectId);

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(despawnPkt);
		Broadcast(sendBuffer, objectId);

		// ������ ���� LeavePlayer�� ȣ���߱� ������, �� �������� �̹� _players���� ���ŵǾ� ����
		if (auto session = player->ownerSession.lock())
			session->Send(sendBuffer);
	}
	return success;
}

void Room::HandleMove(Protocol::C_MOVE pkt)
{

	const uint64 objectId = pkt.info().object_id();

	if (_players.find(objectId) == _players.end())
		return;
	
	// ����
	PlayerRef player = _players[objectId];
	player->playerInfo->CopyFrom(pkt.info());

	// �̵�
	{
		Protocol::S_MOVE movePkt;
		{
			Protocol::PlayerInfo* info = movePkt.mutable_info();
			info->CopyFrom(pkt.info());
		}

		SendBufferRef sendBuffer = ServerPacketHandler::MakeSendBuffer(movePkt);
		Broadcast(sendBuffer);
	}
}

RoomRef Room::GetRoomRef()
{
	return static_pointer_cast<Room>(shared_from_this());
}

bool Room::EnterPlayer(PlayerRef player)
{
	if (_players.find(player->playerInfo->object_id()) != _players.end())
		return false;

	_players.insert(make_pair(player->playerInfo->object_id(), player));

	player->room.store(GetRoomRef());

	return true;
}

bool Room::LeavePlayer(uint64 objectId)
{
	// ���ٸ� ���� ����
	if (_players.find(objectId) == _players.end())
		return false;

	PlayerRef player = _players[objectId];
	player->room.store(weak_ptr<Room>());

	_players.erase(objectId);

	return true;
}

void Room::Broadcast(SendBufferRef sendBuffer, uint64 exceptId)
{
	for (auto& pair : _players)
	{
		PlayerRef player = pair.second;
		if (player->playerInfo->object_id() == exceptId)
			continue;

		GameSessionRef session = player->ownerSession.lock();
		if (session)
			session->Send(sendBuffer);
	}
}