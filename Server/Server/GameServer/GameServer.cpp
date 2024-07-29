#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

class Knight
{
public:
	Knight() : _hp(0), _mp(0) {}
	Knight(int32 hp, int32 mp) : _hp(hp), _mp(mp) {}
	~Knight() {}

private:
	int32 _hp;
	int32 _mp;
};

int main()
{
}
