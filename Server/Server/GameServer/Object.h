#pragma once

class Object : public enable_shared_from_this<Object>
{
public:
	Object();
	virtual ~Object();	

	bool IsPlayer();

public:
	Protocol::ObjectInfo* objectInfo = nullptr;
	Protocol::PosInfo* posInfo = nullptr;

public:
	atomic<weak_ptr<Room>>		room;

protected:
};

