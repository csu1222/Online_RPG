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
// IocpEvent 는 OVERLAPPED 를 첫번째 멤버 변수로 가지고 있을 수도 있고 지금 처럼 상속을 받아도 됩니다. 
// 이때 주의해야할 점이 괜히 virtual 함수로 소멸자를 만들게 되면 클래스의 첫데이터가 OVERLAPPED 가 아니게 됩니다.
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

	// AcceptEx 에서는 ListenSocket 과 AcceptedSocket을 모두 필요로 하기 때문에 다 아우르는 Session 클래스를 다루는 함수가 필요합니다. 
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