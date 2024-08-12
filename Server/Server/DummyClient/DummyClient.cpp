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

	
	// 소켓 리소스 반환 
	::closesocket(clientSocket);
	
	// winsock 종료
	::WSACleanup();
}