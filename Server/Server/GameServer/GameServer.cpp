#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"
#include "Allocator.h"

class Knight
{
public:
	Knight() : _hp(0), _mp(0) 
	{
		cout << "Knight()" << endl;
	}
	Knight(int32 hp, int32 mp) : _hp(hp), _mp(mp) 
	{
		cout << "Knight()" << endl;
	}
	~Knight() 
	{
		cout << "~Knight" << endl;
	}

private:
	int32 _hp;
	int32 _mp;
};

int main()
{

	Vector<Knight> V(100);
}
