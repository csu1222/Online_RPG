#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"

#include "SocketUtils.h"

int main()
{
	// SocketUtils 를 사용한 listenSocket 생성과 bind, listen 
	SOCKET listenSocket = SocketUtils::CreateSocket();

	SocketUtils::BindAnyAddress(listenSocket, 7777);

	SocketUtils::Listen(listenSocket);

	// 아직 비동기 입출력 함수는 사용하지 않습니다. 
	// 나중에 IOCP 까지 만들고 연동할것이기 때문

	SOCKET clientSocket = ::accept(listenSocket, nullptr, nullptr);
	if (clientSocket == INVALID_SOCKET)
	{
		int error = WSAGetLastError();
		cout << "Accept failed with error: " << error << endl;
		// 오류 처리 로직 추가
		return 0; // 프로그램 종료
	}

	cout << "Client Connected!" << endl;

	while (true)
	{

	}

	GThreadManager->Join();
}
