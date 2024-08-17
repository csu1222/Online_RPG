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
	WSAOVERLAPPED overlapped = {};
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

	// Overlapped IO (비동기-논블로킹)
	// - Overlapped 함수를 건다 (WSARecv, WSASend)
	// - Overlapped 함수가 성공했는지 확인 후 
	// -> 성공했으면 결과 얻어서 처리
	// -> 실패했으면 사유를 확인 
	
	// WSASend,WSARecv
	{
		// 인자목록
		// 1) 비동기 입출력 소켓
		// 2) WSABUF 배열의 시작주소 
		// 3) WSABUF 배열의 갯수
		{
			// WSABUF의 사용례
			//char sendBuffer[100];
			//WSABUF wsaBuf[2];
			//wsaBuf[0].buf = sendBuffer;
			//wsaBuf[0].len = 100;

			//char sendBuffer2[100];
			//wsaBuf[1].buf = sendBuffer2;
			//wsaBuf[1].len = 100;

			// 왜 WSABUF의 시작주소와 갯수를 받냐면 
			// Scatter-Gather 기법때문 
			// 쪼개져있는 버퍼들을 한번에 모아서 보내주는 기법
			// 이후 패킷을 보낼때 한번에 뭉쳐서 보낼 수 있습니다. 
		}
		// 4) 보내고 받은 바이트의 수
		// 5) 상세한 옵션인데 일단 0으로 주면 됩니다. 
		// 6) WSAOVERLAPPED 구조체의 주소값
		{
			// WSAOVERLAPPED 는 무엇인가
			// 내부 상세한 데이터중 Handle hEvent 라는 멤버 변수가 있는데 이것에 집중해야합니다. 
			// 이 hEvent에 어떤 방식으로 통지받을지 넣어주는데 여기에 Event 객체를 넣어주면 Event 방식으로 완료 통지를 받게 될것
			// WSAOVERLAPPED wsaOverlapped;
		}
		// 7) 입출력이 완료되면 OS가 호출할 콜백함수 (현재 버전에서는 이것 대신 Event 객체 방식을 사용할것)

		// WSASend()
	}

	// 이번 실습 진행순서 
	// - 비동기 입출력 지원하는 소켓 생성 + 통지 받기위한 이벤트 객체 생성
	// - 비동기 입출력 함수 호출 (위에서 만든 이벤트 객체도 넘겨줌)
	// - 비동기 작업이 바로 완료되지 않으면 , WSA_IO_PENDING 오류코드 가 올것
	// - 비동기 작업이 나중에 완료되면 운영체제에서 이벤트 객체를 signaled 상태로 만들어 완료 상태 알려줌
	// - 이벤트 객체의 signaled 여부를 확인하기 위한 WSAWaitForMultipleEvents 함수 호출 
	// -  WSAGetOverlappedResult 함수를 호출해 비동기 입출력 함수의 결과 확인 및 데이터 처리

	// 실습 시작 
	while (true)
	{	
		// 먼저 클라이언트 소켓을 받는 accept 함수를 호출합니다. 
		SOCKADDR_IN clientAddr;
		int32 addrLen = sizeof(clientAddr);
		SOCKET clientSocket;
		while (true)
		{
			clientSocket = ::accept(listenSocket, (SOCKADDR*)&clientAddr, &addrLen);
			if (clientSocket != INVALID_SOCKET)
				break;

			long acceptErrorCode = ::WSAGetLastError();
			if (acceptErrorCode == WSAEWOULDBLOCK)
				continue;

			cout << "accept Error Code : " << acceptErrorCode << endl;
			return 0;
		}

		// Session 구조체에서 WSAOVERLAPPED 멤버 변수를 추가했습니다. 
		Session session = Session{ clientSocket };
		// 위에서 할일중 하나인 완료통지를 받을 WSAEvent 객체를 만들어 Session의 멤버 변수 overlapped 에 세팅
		WSAEVENT wsaEvent = ::WSACreateEvent();
		session.overlapped.hEvent = wsaEvent;

		cout << "Client Accept" << endl;

		// 이제 클라이언트로부터 받은 데이터를 처리합니다. 
		while (true)
		{
			// 비동기-논블로킹 함수인 WSARecv 필요한 인자들을 만들어 넘겨줍니다. 
			WSABUF wsaBuf;
			wsaBuf.buf = session.recvBuffer;	// 이 session.recvBuffer 가 메모리 해제되지 안도록 해야합니다. 
			wsaBuf.len = BUF_SIZE;

			DWORD recvLen = 0;
			DWORD flags = 0;

			// 비동기-논블로킹 함수다 보니 함수를 호출하자마자 빠져나오기는합니다. 
			if (::WSARecv(clientSocket, &wsaBuf, 1, &recvLen, &flags, &session.overlapped, nullptr) == SOCKET_ERROR)
			{
				// 아직 데이터가 안왔으니 Pending 상태 
				// 완료통지를 받습니다.
				if (::WSAGetLastError() == WSA_IO_PENDING)
				{
					// Pending 중이면 이벤트를 통해 완료 통지를 기다립니다. 
					::WSAWaitForMultipleEvents(1, &wsaEvent, TRUE, WSA_INFINITE, FALSE);
					// 빠져나왔다면 어떤 네트워크 이벤트인지 체크 
					::WSAGetOverlappedResult(session.socket, &session.overlapped, &recvLen, FALSE, &flags);
				}
				else
				{
					// TODO : 문제상황 
					break;
				}
			}

			// 빠져나왔다면 WSARecv 가 성공했습니다. 
			cout << "Data Recv Len : " << recvLen << endl;
		}
		// 끝났다면 정리 
		closesocket(clientSocket);
		::WSACloseEvent(wsaEvent);
	}

	// winsock 종료
	::WSACleanup();
}
