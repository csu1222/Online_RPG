#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

#include "SocketUtils.h"
#include "Listener.h"

int main()
{
	Listener listener;
	// listener의 StartAccept 를 바로 호출하면 리스너 소켓의 옵션과 bind, listen 까지 하고 RegisterAccept 까지 호출이 됩니다. 
	listener.StartAccept(NetAddress(L"127.0.0.1" , 7777));

	// 그러면 이제 리스너는 AcceptEx 로 클라이언트의 접속을 기다리게 되니 워커 쓰레드들을 만들어 Dispatch 로 AcceptEx 가 완료 되었는지 추적

	// 워커쓰레드는 계속해서 IocpCore 를 Dispatch 로 관찰을 하면됩니다. 
	for (int32 i = 0; i < 5; i++)
	{
		GThreadManager->Launch([=]()
			{
				while (true)
				{
					GIocpCore.Dispatch();
				}
			});
	}

	GThreadManager->Join();
}
