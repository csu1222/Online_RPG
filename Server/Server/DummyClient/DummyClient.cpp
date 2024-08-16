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

	// Send
	while (true)
	{
		int32 sendLen = ::send(clientSocket, sendBuffer, sizeof(sendBuffer), 0);
		if ( sendLen == SOCKET_ERROR)
		{
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
				continue;

			break;
		}
		cout << "Send Len : " << sendLen << endl;

		this_thread::sleep_for(10ms);
	}
	// Recv 시도 
	while (true)
	{
		char recvBuffer[1000];

		int32 recvLen = ::recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
		// 마찬가지로 recvLen 이 SOCKET_ERROR 라고해서 진짜 에러인지는 아직 모릅니다. 
		if (recvLen == SOCKET_ERROR)
		{
			if (::WSAGetLastError() == WSAEWOULDBLOCK)
				continue;

			break;
		}
		else if (recvLen == 0)
		{
			// 연결 끊김 
			break;
		}

		cout << "Recv Len : " << recvLen << endl;

		break;
	}

	// 소켓 리소스 반환 
	::closesocket(clientSocket);
	
	// winsock 종료
	::WSACleanup();
}