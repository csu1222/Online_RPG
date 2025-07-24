#include "pch.h"
#include "Player.h"

Player::Player()
{
	auto playerInfo = objectInfo->mutable_creature_info();
	playerInfo->set_creature_type(Protocol::CREATURE_TYPE_PLAYER);
}

Player::~Player()
{
}
