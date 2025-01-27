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

bool Object::IsPlayer()
{
	bool result = objectInfo->creature_type() == Protocol::CREATURE_TYPE_PLAYER;
	return result;
}
