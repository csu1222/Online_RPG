#include "pch.h"
#include "CoreGlobal.h"
#include "ThreadManager.h"
#include "DeadLockProfiler.h"

ThreadManager* GThreadManager = nullptr;
DeadLockProfiler* GDeadLockProfiler = nullptr;

class CoreGlobal
{
public:
	CoreGlobal()
	{
		GThreadManager = new ThreadManager();
		GDeadLockProfiler = new DeadLockProfiler();
	}

	~CoreGlobal()
	{
		delete GThreadManager;
		delete GDeadLockProfiler;
	}
} GCoreGlobal;	// 이렇게 만든면 컨텐츠쪽에서 신경쓰지 않아도됩니다.
 