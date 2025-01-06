#pragma once

class GameSession;
class Room;

class Player : public enable_shared_from_this<Player>
{
public:
	Player();
	virtual ~Player();

public:

	string					name;
	Protocol::PlayerType	type = Protocol::PLAYER_TYPE_NONE;
	Protocol::PlayerInfo*	playerInfo = nullptr;
	weak_ptr<GameSession>			ownerSession; // Cycle

public:
	atomic<weak_ptr<Room>>		room;
};

