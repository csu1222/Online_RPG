#include "pch.h"
#include "Monster.h"

Monster::Monster()
{	
	auto cretureInfo = objectInfo->mutable_creature_info();
	cretureInfo->set_creature_type(Protocol::CREATURE_TYPE_MONSTER);
	//objectInfo->set_monster_type(Protocol::MONSTER_TYPE_BAT);
	//objectInfo->set_hp(100);
	//objectInfo->set_max_hp(100);
	//objectInfo->set_attack(10);
	//objectInfo->set_defense(5);
	//objectInfo->set_speed(1.0f);
}

Monster::~Monster()
{
}
