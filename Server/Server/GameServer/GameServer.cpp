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

// 완료 루틴 함수 
void CALLBACK RecvCallback(DWORD error, DWORD recvLen, LPWSAOVERLAPPED overlapped, DWORD flags)
{
	// TODO 

	cout << "Data Recv Len Callback = " << recvLen << endl;

	// 만약 에코 서버를 만든다면 여기서 WSASend 호출 
}

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


	// Overlapped 모델 (Completion Routine 콜백 기반) 이번 실습 진행순서 
	// - 비동기 입출력 지원하는 소켓 생성 , 콜백을 위한 함수(완료 루틴)를 만듬
	// - 비동기 입출력 함수 호출 (완료 루틴의 시작주소를 넘겨줌)
	// - 비동기 작업이 바로 완료되지 않으면 , WSA_IO_PENDING 오류코드 가 올것
	// - 비동기 입출력 함수 호출한 쓰레드가 완료루틴을 받을 상태라면 -> Alertable Wait 함수로 만듭니다. 
	//  ex) WaitForSingleObjectEx, WaitForMultipleObjectEx, SleepEx, WSAWaitForMultipleEvents 등으로 Alertable Wait 상태로 만듬
	// - 비동기 작업이 나중에 완료되고 비동기 입출력 함수를 호출한 쓰레드가 Alertable Wait 상태라면 
	//		운영체제에서 완료루틴 호출 그런데 이 완료 루틴 호출 시점이 문제 
	// - 완료 루틴 호출이 모두 끝나면, 쓰레드는 Alertable Wait 상태에서 빠져나온다

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
		WSAEVENT wsaEvent = ::WSACreateEvent();
		// WSAOVERLAPPED 객체에 이벤트를 연동하는 부분이 없어집니다. 
		// session.overlapped.hEvent = wsaEvent;

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

			// WSARecv의 마지막 인자에 콜백함수를 넣어줄겁니다. 
			//void
			//(CALLBACK * LPWSAOVERLAPPED_COMPLETION_ROUTINE)(
			//	IN DWORD dwError,
			//	IN DWORD cbTransferred,
			//	IN LPWSAOVERLAPPED lpOverlapped,
			//	IN DWORD dwFlags
			//	);
			//  이런 시그니처의 함수를 받아주고 있습니다. 
			if (::WSARecv(clientSocket, &wsaBuf, 1, &recvLen, &flags, &session.overlapped, RecvCallback) == SOCKET_ERROR)
			{
				// 아직 데이터가 안왔으니 Pending 상태 
				if (::WSAGetLastError() == WSA_IO_PENDING)
				{
					// Pending 중이면 쓰레드를 Alertable Wait 상태로 바꿔 줘야 합니다. 
					::SleepEx(INFINITE, TRUE);
					// 빠져나왔다면 어떤 네트워크 이벤트인지 체크 
					//::WSAGetOverlappedResult(session.socket, &session.overlapped, &recvLen, FALSE, &flags);
				}
				else
				{
					// TODO : 문제상황 
					break;
				}
			}
			else
			{
				cout << "Data Recv Len : " << recvLen << endl;
			}

		}
		// 끝났다면 정리 
		closesocket(clientSocket);
		::WSACloseEvent(wsaEvent);
	}

	// winsock 종료
	::WSACleanup();
}
