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

void HandleError(const char* cause)
{
	int32 errCode = ::WSAGetLastError();
	cout << cause << "Socket ErrorCode :" << errCode << endl;
}

enum
{
	BUF_SIZE = 1000
};

// 입출력에 필요한 데이터 들을 모아둠
struct Session
{
	SOCKET socket = INVALID_SOCKET;
	char recvBuffer[BUF_SIZE] = {};
	int32 recvByte = 0;
	int32 sendByte = 0;
};

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

	// 논블로킹 소켓 생성 

	// IPv4, TCP 소켓
	SOCKET listenSocket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET)
		return 0;

	// 논블로킹으로 설정
	u_long on = 1;
	if (::ioctlsocket(listenSocket, FIONBIO, &on) == INVALID_SOCKET)
		return 0;

	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = ::htonl(INADDR_ANY);
	serverAddr.sin_port = ::htons(7777);

	if (::bind(listenSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR)
		return 0;


	if (::listen(listenSocket, SOMAXCONN) == SOCKET_ERROR)
		return 0;

	cout << "Accept" << endl;

	// Select 모델 = select 함수가 핵심이 되는 모델 
	// 소켓 함수 호출이 성공할 시점을 미리 알 수 있다 라는 컨셉

	// 문제 상황)
	// 수신버퍼에 데이터가 없는데, read를 한다거나 
	// 송신버퍼가 꽉 찼는데 , write 를 한다거나 

	// 성공 시점을 미리 알 수 있다가 핵심이라서 소켓이 블로킹이든 논블로킹이든 별 상관 없다 
	// - 블로킹 소켓 에서 사용하면 : 조건이 만족되지 않아서 블로킹 되는 상황 예방
	// - 논블로킹 소켓 : 조건이 만족되지 않아서 불필요하게 반복 체크하는 상황을 예방 


	// socket set 
	// 1) 읽기 [ ] 쓰기 [ ] 예외 [ ] 관찰대상 등록
	// 읽기와 쓰기를 주로 사용할 것임
	// 2) select함수 호출 (readSet, writeSet, excpetSet 인자로 넣어줌) -> 관찰시작 
	// 3) 적어도 하나의 소켓이 준비되면 리턴 -> 낙오자는 알아서 제거됨 (다음 select 호출때 다시 채워줘야함)
	// 4) 남은 소켓 체크해서 진행 

	// socket set 만들기 
	//{
	//	fd_set read;
	//	FD_ZERO(&read);	// 비우기
	//	SOCKET testSock;
	//	FD_SET(testSock, &read);	// testSock 을 read 라는 세트에 넣기
	//	FD_CLR(testSock, &read);	// testSock 을 read 세트에서 제거 
	//	FD_ISSET(testSock, &read);	// testSock이 read 세트에 들어있으면 0이 아닌값을 리턴 
	//}
	
	// 각 소켓마다 관리할 세션들을 생성 
	vector<Session> sessions;
	sessions.reserve(100);

	// select에서 사용할 소켓 세트들을 생성
	fd_set reads;
	fd_set writes;

	while (true)
	{
		// 매 루프마다 초기화 해줘야 합니다. 
		FD_ZERO(&reads);
		FD_ZERO(&writes);

		// ListenSocket 등록 accept 할 대상이 있는지 기다리는 소켓이니 reads 에 넣습니다. 
		FD_SET(listenSocket, &reads);

		// sessions 에 있는 모든 소켓들을 등록 
		for (Session& s : sessions)
		{
			// 소켓을어느 소켓 세트에 등록할지 정해야 하는데 지금 테스트는 에코서버이기때문에 
			// 이전 동작에 따라 버퍼 길이를 측정해 세트를 골라줍니다. 
			if (s.recvByte <= s.sendByte)
				FD_SET(s.socket, &reads);
			else
				FD_SET(s.socket, &writes);
		}

		// select 함수 호출 
		// 첫번째 인자는 리눅스와 인자 갯수를 맞추기 위함, 뒤의 두 인자는 앞에 부터 exceptSet, timeout 인데 
		// exceptSet 은 사용하지 않을것이라 null, timeout 은 select 를 언제까지 기다릴것인지 null 을 주면 무한 대기
		int32 retVal = ::select(0, &reads, &writes, nullptr, nullptr);

		if (retVal == SOCKET_ERROR)
			break;

		// select가 리턴되면 등록된 세트에서 준비된 소켓 말고는 다 탈락을 시키기 때문에 FD_ISSET 으로 동작 성공한 소켓을 찾을 수 있습니다. 

		// Listen 소켓 체크 
		if (FD_ISSET(listenSocket, &reads))
		{
			// listen 소켓이 accept 할 준비가 됨 
			SOCKADDR_IN clientAddr;
			int32 addrLen = sizeof(clientAddr);
			SOCKET clientSocket = ::accept(listenSocket, (SOCKADDR*)&clientAddr, &addrLen);
			// select 를 지나 FD_ISSET 을 통과 했다면 accept 를 성공할 준비가 되어있다는뜻 이지만 혹시 몰라 한번 체크
			if (clientSocket != INVALID_SOCKET)
			{
				cout << "Client Accept Success" << endl;

				// 접속한 클라이언트 소켓도 sessions 에 등록해줍니다. 
				sessions.push_back(Session{ clientSocket });
			}
		}

		// 나머지 소켓 대상체크 
		for (Session& s : sessions)
		{
			// read 체크
			if (FD_ISSET(s.socket, &reads))
			{
				int32 recvLen = ::recv(s.socket, s.recvBuffer, BUF_SIZE, 0);
				if (recvLen <= 0)
				{
					// TODO : sessions 에서 제거
					continue;
				}

				s.recvByte = recvLen;
			}

			// write 체크
			if (FD_ISSET(s.socket, &writes))
			{
				// 블로킹 모드 -> 모든 데이터를 다 보냄
				// 논블로킹 모드 -> 데이터의 일부만 보낼 수 있슴(상대망 수신 버퍼 상황에 따라)
				int32 sendLen = ::send(s.socket, &s.recvBuffer[s.sendByte], s.recvByte - s.sendByte, 0);
				if (sendLen == SOCKET_ERROR)
				{
					// TODO: sessions에서 제거 
					continue;
				}

				s.sendByte += sendLen;
				if (s.recvByte == s.sendByte)
				{
					s.recvByte = 0;
					s.sendByte = 0;
				}
			}
		}
	}


	// winsock 종료
	::WSACleanup();
}
