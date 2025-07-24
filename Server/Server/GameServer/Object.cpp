#include "pch.h"
#include "Object.h"

Object::Object()
{
	objectInfo = new Protocol::ObjectInfo();
	posInfo = new Protocol::PosInfo();
	objectInfo->set_allocated_pos_info(posInfo);
}

Object::~Object()
{
	delete objectInfo;
}

bool Object::IsCreature()
{
	bool result = objectInfo->object_type() == Protocol::ObjectType::OBJECT_TYPE_CREATURE;
	return result;
}

bool Object::IsPlayer()
{
	bool result = objectInfo->creature_info().creature_type() == Protocol::CREATURE_TYPE_PLAYER;
	return result;
}

bool Object::IsMonster()
{
	bool result = objectInfo->creature_info().creature_type() == Protocol::CREATURE_TYPE_MONSTER;
	return result;
}
