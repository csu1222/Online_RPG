#pragma once
#include "IocpCore.h"
#include "NetAddress.h"

class AcceptEvent;

/*--------------
	Listener
---------------*/

class Listener : public IocpObject
{
public:
	Listener() = default;
	~Listener();

public:
	/* �ܺο��� ��� */
	bool StartAccept(NetAddress netAddress);
	void CloseSocket();

public:
	/* �������̽� ���� IocpObject�� ��ӹ޾����� */
	virtual HANDLE GetHandle() override;
	virtual void Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) override;

private:
	/* ���� ���� */
	void RegisterAccept(AcceptEvent* acceptEvent);
	void ProcessAccept(AcceptEvent* acceptEvent);

protected:
	// listenerSocket �̶�� �������
	SOCKET _socket = INVALID_SOCKET;
	// Ŭ���̾�Ʈ���� �����Ҷ� ������ Accept Event �� 
	Vector<AcceptEvent*> _acceptEvents;
};
