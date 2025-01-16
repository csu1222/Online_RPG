#pragma once
#include "JobQueue.h"

class Room : public JobQueue
{
public:
	Room();
	virtual ~Room();

	bool HandleEnterPlayer(PlayerRef player);
	bool HandleLeavePlayer(PlayerRef player);

	void HandleMove(Protocol::C_MOVE pkt);

	RoomRef GetRoomRef();

private:
	bool EnterPlayer(PlayerRef player);
	bool LeavePlayer(uint64 objectId);

public:
	// 싱글쓰레드 환경인마냥 코딩
	void Broadcast(SendBufferRef sendBuffer, uint64 exceptId = 0);

private:
	unordered_map<uint64, PlayerRef> _players;
};

extern RoomRef GRoom;