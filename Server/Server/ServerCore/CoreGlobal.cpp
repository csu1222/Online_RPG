#include "pch.h"
#include "CoreGlobal.h"
#include "ThreadManager.h"

ThreadManager* GThreadManager = nullptr;

class CoreGlobal
{
public:
	CoreGlobal()
	{
		GThreadManager = new ThreadManager();
	}
	~CoreGlobal()
	{

		delete GThreadManager;
	}
} GCoreGlobal;	// 이렇게 만든면 컨텐츠쪽에서 신경쓰지 않아도됩니다.
