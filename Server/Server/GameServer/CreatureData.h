#pragma once
#include "Protocol.pb.h"


class CreatureData
{
public:
	CreatureData()
	{
		creatureInfo = make_shared<Protocol::CreatureInfo>();
	}

	CreatureData(shared_ptr<Protocol::CreatureInfo> info)
	{
		creatureInfo = info;
	}

	virtual ~CreatureData()
	{
		if (creatureInfo)
			creatureInfo.reset();
	}

public:
	bool SetCreatureInfo(shared_ptr<Protocol::CreatureInfo> info)
	{
		if (info == nullptr)
			return false;
		creatureInfo = info;
		return true;
	}

	shared_ptr<Protocol::CreatureInfo> GetCreatureInfo()
	{
		return creatureInfo;
	}

public:
	shared_ptr<Protocol::CreatureInfo> creatureInfo = nullptr;
};
