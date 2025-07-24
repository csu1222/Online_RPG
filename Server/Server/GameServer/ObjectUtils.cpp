#include "pch.h"
#include "ObjectUtils.h"
#include "Player.h"
#include "Monster.h"
#include "GameSession.h"

atomic<int64> ObjectUtils::s_IdGenerator = 1;
//atomic<int64> ObjectUtils::s_MonsterIdGenerator = 1;

PlayerRef ObjectUtils::CreatePlayer(GameSessionRef session)
{
	// ID 발급
	const int64 newId =	GenerateId(PLAYER);

	PlayerRef player = make_shared<Player>();
	player->objectInfo->set_object_id(newId);
	player->posInfo->set_object_id(newId);

	player->session = session;
	session->_currentPlayer.store(player);

	return player;
}

MonsterRef ObjectUtils::CreateMonster(RoomRef room)
{
	// ID 발급
	const int64 newId = GenerateId(MONSTER);

	MonsterRef monster = make_shared<Monster>();
	monster->objectInfo->set_object_id(newId);
	monster->posInfo->set_object_id(newId);

	cout << "Monster Created In Object Utils : " << newId << endl;

	return monster;
}
