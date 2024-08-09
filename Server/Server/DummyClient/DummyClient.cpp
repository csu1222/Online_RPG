#include "pch.h"
#include <iostream>
#include "CorePch.h"

#include "winsock2.h"
#include "MSWSock.h"
#include "WS2tcpip.h"
#pragma comment(lib, "ws2_32.lib")

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

	// TODO
	// 클라이언트 소켓 만들기 
	// 인자는 총 3개 
	// int af : address family 주소 패밀리 주로 기억해야 하는 것은 AF_INET(IPv4), AF_INET6(IPv6)
	// int type : 새 소켓의 형식 사양 TCP 프로토콜에 사용되는 SOCK_STREAM 혹은 UDP 에 사용되는 SOCK_DGRAM 을 주로 사용한다.
	// int protocol : 사용할 프로토콜 사용할 통신의 세세한 종류에 따라 고를 수 있는데 0 값을 넣어주면 알아서 골라주게 됩니다. 
	// 반환값은 socket descripter 
	SOCKET clientSocket = ::socket(AF_INET, SOCK_STREAM, 0);

	// SOCKET 타입에 커서를 가져다 대면 UINT_PTR 입니다. 정수의 포인터인것인데
	// 운영체제가 이 해당 번호에 해당하는 소켓리소스를 통해 네트워크 통신을 할 수 있게 됩니다. 

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
	// serverAddr.sin_addr.s_addr = ::inet_addr("127.0.0.1");	// 접속할 주소 하지만 너무 오래되서 사용하는걸 권장하지 않는 방식 
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);	// 현대적인 방식
	serverAddr.sin_port = ::htons(7777);	// 접속할 포트 번호 

	// 정해진 주소로 연결시도 
	// 인자는 순서대로 소켓, 주소 구조체, 주소구조체의 사이즈를 받습니다. 
	if (::connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
	{
		int32 errCode = ::WSAGetLastError();
		cout << "Connect ErrorCode : " << errCode << endl;
		return 0;
	}

	// 연결성공 이 후로 데이터 송수신 가능 

	cout << "Connecte To Server" << endl;

	while (true)
	{
		// TODO

		char sendBuffer[100] = "Hello World!";

		// 인자는 차례대로 
		// 소켓, 버퍼, 버퍼의 길이, 플레그  이중 플레그는 왠만해서 0을 주면 알아서 골라줍니다.
		
		for (int32 i = 0; i < 10; i++)
		{
			int32 resultCode = ::send(clientSocket, sendBuffer, sizeof(sendBuffer), 0);
			if (resultCode == SOCKET_ERROR)
			{
				int32 errCode = ::WSAGetLastError();
				cout << "Send ErrorCode : " << errCode << endl;
				return 0;
			}
		}

		cout << "Send Data! Len = " << sizeof(sendBuffer) << endl;
		

		//// echo server : 받은 데이터를 그대로 토스 
		//char recvBuffer[1000];

		//// recv 의 반환 값은 받은 데이터의 바이트크기 입니다. 
		//int32 recvLen = ::recv(clientSocket, recvBuffer, sizeof(recvBuffer), 0);
		//if (recvLen <= 0)
		//{
		//	int32 errCode = ::WSAGetLastError();
		//	cout << "Recv ErrorCode : " << errCode << endl;
		//	return 0;
		//}

		//cout << "Recv Data! Data = " << recvBuffer << endl;
		//cout << "Recv Data! Len = " << recvLen << endl;


		this_thread::sleep_for(1s);
	} 
	
	// 소켓 리소스 반환 
	::closesocket(clientSocket);
	
	// winsock 종료
	::WSACleanup();
}