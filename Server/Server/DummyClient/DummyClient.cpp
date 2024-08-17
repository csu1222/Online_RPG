#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include "winsock2.h"
#include "MSWSock.h"
#include "WS2tcpip.h"
#pragma comment(lib, "ws2_32.lib")


void HandleError(const char* cause)
{
	int32 errCode = ::WSAGetLastError();
	cout << cause << "Socket ErrorCode :" << errCode << endl;
}

int main()
{
	this_thread::sleep_for(1s);

	// winsock 라이브러리 초기화  (ws2_32 라이브러리 초기화)
	// WORD 타입 윈속 버전과 윈속을 초기화 한 후의 데이터를 받아줄 WSAData 의 주소 
	WORD wVersionRequestes;
	WSAData wsaData;

	int err;

	wVersionRequestes = MAKEWORD(2, 2);
	err = ::WSAStartup(wVersionRequestes, &wsaData);

	// err 가 0 이면 성공 아니면 실패
	if (err != 0)
	{
		/* Tell the user that we could not find a usable */
		/* Winsock DLL.                                  */
		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}

	// wsaData.wVersion 의 상위 바이트는 부버전 하위 바이트는 주버전을 뜻함 
	// 아래 코드는 winsock 버전이 2.2 가 아닌경우의 예외 처리를 하고 있습니다. 
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		/* Tell the user that we could not find a usable */
		/* WinSock DLL.                                  */
		printf("Could not find a usable version of Winsock.dll\n");
		WSACleanup();
		return 1;
	}
	else
		printf("The Winsock 2.2 dll was found okay\n");


	// IPv4, TCP 소켓
	SOCKET clientSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET)
		return 0;

	// 논블로킹으로 설정
	u_long on = 1;
	if (::ioctlsocket(clientSocket, FIONBIO, &on) == INVALID_SOCKET)
		return 0;

	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	serverAddr.sin_port = ::htons(7777);

	// Connect
	while (true)
	{
		if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		{
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
				continue;
			// connect는 WSAEISCONN 연결된 상태라면 브레이크 
			if (::WSAGetLastError() == WSAEISCONN)
				break;

			// Error
			break;
		}
	}

	cout << "Connected To Server" << endl;

	char sendBuffer[100] = "Hello World";
	// WSAEVENT 객체 생성 
	WSAEVENT wsaEvent = ::WSACreateEvent();
	WSAOVERLAPPED overlapped = {};
	overlapped.hEvent = wsaEvent;

	// Send
	while (true)
	{
		// 비동기-논블로킹 함수인 WSASend 필요한 인자들을 만들어 넘겨줍니다. 
		WSABUF wsaBuf;
		wsaBuf.buf = sendBuffer;
		wsaBuf.len = 100;

		DWORD sendLen = 0;
		DWORD flags = 0;

		// 비동기-논블로킹 함수다 보니 함수를 호출하자마자 빠져나오기는합니다. 
		if (::WSASend(clientSocket, &wsaBuf, 1, &sendLen, flags, &overlapped, nullptr) == SOCKET_ERROR)
		{
			// 아직 데이터가 안왔으니 Pending 상태 
			// 완료통지를 받습니다.
			if (::WSAGetLastError() == WSA_IO_PENDING)
			{
				// Pending 중이면 이벤트를 통해 완료 통지를 기다립니다. 
				::WSAWaitForMultipleEvents(1, &wsaEvent, TRUE, WSA_INFINITE, FALSE);
				// 빠져나왔다면 어떤 네트워크 이벤트인지 체크 
				::WSAGetOverlappedResult(clientSocket, &overlapped, &sendLen, FALSE, &flags);
			}
			else
			{
				// TODO : 문제상황 
				break;
			}
		}

		// 빠져나왔다면 WSARecv 가 성공했습니다. 
		cout << "Send Len : " << sendLen << endl;

		this_thread::sleep_for(1s);
	}

	// 소켓 리소스 반환 
	::closesocket(clientSocket);
	
	// winsock 종료
	::WSACleanup();
}