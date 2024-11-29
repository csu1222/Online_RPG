#pragma once
#include "IocpCore.h"
#include "NetAddress.h"

class AcceptEvent;
class ServerService;

/*--------------
	Listener
---------------*/

class Listener : public IocpObject
{
public:
	Listener() = default;
	~Listener();

public:
	/* 외부에서 사용 */
	bool StartAccept(ServerServiceRef serverService);
	void CloseSocket();

public:
	/* 인터페이스 구현 IocpObject를 상속받았으니 */
	virtual HANDLE GetHandle() override;
	virtual void Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) override;

private:
	/* 수신 관련 */
	void RegisterAccept(AcceptEvent* acceptEvent);
	void ProcessAccept(AcceptEvent* acceptEvent);

protected:
	// listenerSocket 이라고 만들던것
	SOCKET _socket = INVALID_SOCKET;
	// 클라이언트들이 접속할때 들어오는 Accept Event 들 
	vector<AcceptEvent*> _acceptEvents;
	ServerServiceRef _service;
};

