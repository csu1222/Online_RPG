#include "pch.h"
#include "ServerPacketHandler.h"
#include "Player.h"
#include "Room.h"
#include "GameSession.h"
#include "ObjectUtils.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];
//
//// ���� ������ �۾���
//
//bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
//{
//	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
//	// TODO : Log
//	return false;
//}
//
//bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt)
//{
//	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);
//
//	// TODO : Validation üũ
//
//	Protocol::S_LOGIN loginPkt;
//	loginPkt.set_success(true);
//
//	// DB���� �÷��� ������ �ܾ�´�
//	// GameSession�� �÷��� ������ ���� (�޸�)
//
//	// ID �߱� (DB ���̵� �ƴϰ�, �ΰ��� ���̵�)
//	static atomic<uint64> idGenerator = 1;
//
//	{
//		auto player = loginPkt.add_players();
//		player->set_name(u8"DB�����ܾ���̸�1");
//		player->set_playertype(Protocol::PLAYER_TYPE_KNIGHT);
//
//		PlayerRef playerRef = make_shared<Player>();
//		playerRef->playerId = idGenerator++;
//		playerRef->name = player->name();
//		playerRef->type = player->playertype();
//		playerRef->ownerSession = gameSession;
//
//		gameSession->_players.push_back(playerRef);
//	}
//
//	{
//		auto player = loginPkt.add_players();
//		player->set_name(u8"DB�����ܾ���̸�2");
//		player->set_playertype(Protocol::PLAYER_TYPE_MAGE);
//
//		PlayerRef playerRef = make_shared<Player>();
//		playerRef->playerId = idGenerator++;
//		playerRef->name = player->name();
//		playerRef->type = player->playertype();
//		playerRef->ownerSession = gameSession;
//
//		gameSession->_players.push_back(playerRef);
//	}
//
//	auto sendBuffer = ServerPacketHandler::MakeSendBuffer(loginPkt);
//	session->Send(sendBuffer);
//
//	return true;
//}
//
//bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
//{
//	GameSessionRef gameSession = static_pointer_cast<GameSession>(session);
//
//	uint64 index = pkt.playerindex();
//	// TODO : Validation
//
//	gameSession->_currentPlayer = gameSession->_players[index]; // READ_ONLY?
//	gameSession->_room = GRoom;
//
//	GRoom->DoAsync(&Room::Enter, gameSession->_currentPlayer);
//
//	Protocol::S_ENTER_GAME enterGamePkt;
//	enterGamePkt.set_success(true);
//	auto sendBuffer = ServerPacketHandler::MakeSendBuffer(enterGamePkt);
//	gameSession->_currentPlayer->ownerSession->Send(sendBuffer);
//
//	return true;
//}
//
//bool Handle_C_CHAT(PacketSessionRef& session, Protocol::C_CHAT& pkt)
//{
//	std::cout << pkt.msg() << endl;
//
//	Protocol::S_CHAT chatPkt;
//	chatPkt.set_msg(pkt.msg());
//	auto sendBuffer = ServerPacketHandler::MakeSendBuffer(chatPkt);
//
//	GRoom->DoAsync(&Room::Broadcast, sendBuffer);
//
//	return true;
//}

bool Handle_INVALID(PacketSessionRef& session, BYTE* buffer, int32 len)
{
	PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
	// TODO : Log
	return false;
}

bool Handle_C_LOGIN(PacketSessionRef& session, Protocol::C_LOGIN& pkt)
{
	// TODO : DB���� Account ������ �ܾ�´�
	// TODO : DB���� �÷��̾� ������ �ܾ�´�

	Protocol::S_LOGIN loginPkt;

	for (int32 i = 0; i < 3; i++)
	{
		Protocol::PlayerInfo* player = loginPkt.add_players();

		player->set_x(Utils::GetRandom(0.f, 100.f));
		player->set_y(Utils::GetRandom(0.f, 100.f));
		player->set_z(Utils::GetRandom(0.f, 100.f));
		player->set_yaw(Utils::GetRandom(0.f, 45.f));
	}

	loginPkt.set_success(true);

	SEND_PACKET(loginPkt);

	return true;
}

bool Handle_C_ENTER_GAME(PacketSessionRef& session, Protocol::C_ENTER_GAME& pkt)
{
	// �÷��̾ ���� 
	PlayerRef player = ObjectUtils::CreatePlayer(static_pointer_cast<GameSession>(session));

	// �濡 ����
	GRoom->HandleEnterPlayerLocked(player);

	return true;
}

bool Handle_C_LEAVE_GAME(PacketSessionRef& session, Protocol::C_LEAVE_GAME& pkt)
{
	auto gameSession = static_pointer_cast<GameSession>(session);

	auto player = gameSession->_currentPlayer.load();
	if (player == nullptr)
		return false;

	RoomRef room = player->room.load().lock();
	if (room == nullptr)
		return false;

	room->HandleLeavePlayerLocked(player);

	return true;
}

bool Handle_C_SPAWN(PacketSessionRef& session, Protocol::C_SPAWN& pkt)
{
	return true;
}

bool Handle_C_CHAT(PacketSessionRef& session, Protocol::C_CHAT& pkt)
{
	auto Msg = pkt.msg();


	return true;
}
