#pragma once
#include "Object.h"

class Creature :
	public Object
{
public:
	Creature();
	virtual ~Creature();

public:
	bool SetData(WCHAR* SetDataName, float SetDataValue);

	float GetData(const WCHAR* GetDataName);

private:
	CreatureDataRef creatureData = nullptr;
};

