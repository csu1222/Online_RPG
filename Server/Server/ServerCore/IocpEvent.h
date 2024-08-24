#pragma once

class Session;

enum class EventType : uint8
{
	Connect,
	Accept,
	//PreRecv,
	Recv,
	Send
};

/*--------------
	IocpEvent
---------------*/
// IocpEvent �� OVERLAPPED �� ù��° ��� ������ ������ ���� ���� �ְ� ���� ó�� ����� �޾Ƶ� �˴ϴ�. 
// �̶� �����ؾ��� ���� ���� virtual �Լ��� �Ҹ��ڸ� ����� �Ǹ� Ŭ������ ù�����Ͱ� OVERLAPPED �� �ƴϰ� �˴ϴ�.
class IocpEvent : public OVERLAPPED
{
public:
	IocpEvent(EventType type);

	void		Init();
	EventType	GetType() { return _type; }

protected:
	EventType	_type;
};

/*----------------
	ConnectEvent
-----------------*/

class ConnectEvent : public IocpEvent
{
public:
	ConnectEvent() : IocpEvent(EventType::Connect) { }
};

/*----------------
	AcceptEvent
-----------------*/

class AcceptEvent : public IocpEvent
{
public:
	AcceptEvent() : IocpEvent(EventType::Accept) { }

	// AcceptEx ������ ListenSocket �� AcceptedSocket�� ��� �ʿ�� �ϱ� ������ �� �ƿ츣�� Session Ŭ������ �ٷ�� �Լ��� �ʿ��մϴ�. 
	void		SetSession(Session* session) { _session = session; }
	Session*	GetSession() { return _session; }

private:
	Session*	_session = nullptr;
};

/*----------------
	RecvEvent
-----------------*/

class RecvEvent : public IocpEvent
{
public:
	RecvEvent() : IocpEvent(EventType::Recv) { }
};

/*----------------
	SendEvent
-----------------*/

class SendEvent : public IocpEvent
{
public:
	SendEvent() : IocpEvent(EventType::Send) { }
};