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

	SOCKET clientSocket = ::socket(AF_INET, SOCK_DGRAM, 0);

	// 소켓을 생성하는데 실패한 예외 처리
	if (clientSocket == INVALID_SOCKET)
	{
		int32 errCode = ::WSAGetLastError();
		cout << "Create Socket ErrorCode : " << errCode << endl;
		return 0;
	}

	// 접속할 서버의 주소를 기입
	SOCKADDR_IN serverAddr; // IPv4 에서 사용되는 주소객체
	::memset(&serverAddr, 0, sizeof(serverAddr));	// serverAddr를 0으로 밀기
	serverAddr.sin_family = AF_INET;	// 사용할 주소체계
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);	// 현대적인 방식
	serverAddr.sin_port = ::htons(7777);	// 접속할 포트 번호 

	// UDP 는 Connect도 안하고 바로 송신 가능
	while (true)
	{
		// TODO

		char sendBuffer[100] = "Hello World!";

		
		for (int32 i = 0; i < 10; i++)
		{
			int32 resultCode = ::sendto(clientSocket, sendBuffer, sizeof(sendBuffer), 0, (SOCKADDR*)&serverAddr, sizeof(serverAddr));
			if (resultCode == SOCKET_ERROR)
			{
				HandleError("SendTo");
				return 0;
			}
		}

		cout << "Send Data! Len = " << sizeof(sendBuffer) << endl;
		
		// Connect 가 된것이 아니다 보니 수신할때 상대가 누구인지 체크해야합니다. 
		char recvBuffer[1000];

		SOCKADDR_IN recvAddr;
		::memset(&recvAddr, 0, sizeof(recvAddr));
		int32 addLen = sizeof(recvAddr);

		// recv 의 반환 값은 받은 데이터의 바이트크기 입니다. 
		int32 recvLen = ::recvfrom(clientSocket, recvBuffer, sizeof(recvBuffer), 0, (SOCKADDR*)&recvAddr, &addLen );
		if (recvLen <= 0)
		{
			HandleError("RecvFrom");
			return 0;
		}

		cout << "Recv Data! Data = " << recvBuffer << endl;
		cout << "Recv Data! Len = " << recvLen << endl;


		this_thread::sleep_for(1s);
	} 
	
	// 소켓 리소스 반환 
	::closesocket(clientSocket);
	
	// winsock 종료
	::WSACleanup();
}