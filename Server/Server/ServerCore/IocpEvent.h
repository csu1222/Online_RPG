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

public:
	EventType	eventType;
	IocpObjectRef owner;
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

// 세션도 세어드 포인터로 들고 있게
class AcceptEvent : public IocpEvent
{
public:
	AcceptEvent() : IocpEvent(EventType::Accept) { }

public:
	SessionRef	session = nullptr;
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