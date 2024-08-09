#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>
#include "ThreadManager.h"
#include "Memory.h"
#include "Allocator.h"

#include "winsock2.h"
#include "MSWSock.h"
#include "WS2tcpip.h"
#pragma comment(lib, "ws2_32.lib")

int main()
{
	// winsock 초기화는 공통적인 부분
	WORD wVersionRequestes;
	WSAData wsaData;

	int err;

	wVersionRequestes = MAKEWORD(2, 2);
	err = ::WSAStartup(wVersionRequestes, &wsaData);

	// err 가 0 이면 성공 아니면 실패
	if (err != 0)
	{
		printf("WSAStartup failed with error: %d\n", err);
		return 1;
	}

	// wsaData.wVersion 의 상위 바이트는 부버전 하위 바이트는 주버전을 뜻함 
	// 아래 코드는 winsock 버전이 2.2 가 아닌경우의 예외 처리를 하고 있습니다. 
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
		printf("Could not find a usable version of Winsock.dll\n");
		WSACleanup();
		return 1;
	}
	else
		printf("The Winsock 2.2 dll was found okay\n");


	// 서버의 소켓 만들기 
	SOCKET listenSocket = ::socket(AF_INET, SOCK_STREAM, 0);

	// 소켓을 생성하는데 실패한 예외 처리
	if (listenSocket == INVALID_SOCKET)
	{
		int32 errCode = ::WSAGetLastError();
		cout << "Create Socket ErrorCode : " << errCode << endl;
		return 0;
	}

	// 서버는 연결할 목적지 주소가 아니라 서버 자신의 주소를 설정
	SOCKADDR_IN serverAddr; // IPv4 에서 사용되는 주소객체
	::memset(&serverAddr, 0, sizeof(serverAddr));	// serverAddr를 0으로 밀기
	serverAddr.sin_family = AF_INET;	// 사용할 주소체계
	serverAddr.sin_addr.s_addr = ::htonl(INADDR_ANY);	// 주소를 알아서 넣어달라 (고정주소를 넣어주면 딱 그 주소만 사용해야 하기 때문)
	serverAddr.sin_port = ::htons(7777);	// 접속할 포트 번호 

	// listen socket 에 서버 주소를 주고 bind
	if (::bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		int32 errCode = ::WSAGetLastError();
		cout << "Bind ErrorCode : " << errCode << endl;
		return 0;
	}

	// 연결준비 완료 
	// 인자로 소켓과 백로그라는 것을 받는데 백로그는 최대 연결 대기열 번호 
	if (::listen(listenSocket, 10) == SOCKET_ERROR)
	{
		int32 errCode = ::WSAGetLastError();
		cout << "Listen ErrorCode : " << errCode << endl;
		return 0;
	}

	// 연결 성공 후 데이터 송수신 가능 

	while (true)
	{
		// 클라이언트가 connect 요청을 했다면 그것을 승락하는 accept

		SOCKADDR_IN clientAddr;	// 연결시도한 클라이언트의 주소를 받아줄 구조체
		::memset(&clientAddr, 0, sizeof(clientAddr));
		int32 addrLen = sizeof(clientAddr);

		// 클라이언트와 데이터를 주고 받을 소켓 
		SOCKET clientSocket = ::accept(listenSocket, (SOCKADDR*)&clientAddr, &addrLen);
		if (clientSocket == INVALID_SOCKET)
		{
			int32 errCode = ::WSAGetLastError();
			cout << "Accept ErrorCode : " << errCode << endl;
			return 0;
		}

		// 클라이언트 입장
		// 클라이언트의 아이피를 찍어 보겠습니다. 
		char ipAddress[16];
		::inet_ntop(AF_INET, &clientAddr.sin_addr, ipAddress, sizeof(ipAddress));
		cout << "Client Connected! IP = " << ipAddress << endl;

		while (true)
		{
			// 수신할때의 주의점은 받는 데이터의 크기를 모른다는것 
			char recvBuffer[1000];

			// recv 의 반환 값은 받은 데이터의 바이트크기 입니다. 
			int32 recvLen = ::recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
			if (recvLen <= 0)
			{
				int32 errCode = ::WSAGetLastError();
				cout << "Recv ErrorCode : " << errCode << endl;
				return 0;
			}

			cout << "Recv Data! Data = " << recvBuffer << endl;
			cout << "Recv Data! Len = " << recvLen << endl;

			//// echo server : 받은 데이터를 그대로 토스 
			//int32 resultCode = ::send(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
			//if (resultCode == SOCKET_ERROR)
			//{
			//	int32 errCode = ::WSAGetLastError();
			//	cout << "Send ErrorCode : " << errCode << endl;
			//	return 0;
			//}
		}

		// winsock 종료
		::WSACleanup();
	}
}