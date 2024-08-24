#include "pch.h"
#include "IocpEvent.h"

/*--------------
	IocpEvent
---------------*/

IocpEvent::IocpEvent(EventType type) : _type(type)
{
	Init();
}

// 생성자에서 하지 않고 왜 따로 뺏냐면 혹시 다른곳에서 직접 호출하고 싶을 수도 있기 때문
// OVERLAPPED의 내부 값들을 0으로 밀어주는것, 이 내부값은 운영체제에서 알아서 사용하는것이기 때문에 hEvent 말고는 건드릴 일이 없습니다. 
void IocpEvent::Init()
{
	OVERLAPPED::hEvent = 0;
	OVERLAPPED::Internal = 0;
	OVERLAPPED::InternalHigh = 0;
	OVERLAPPED::Offset = 0;
	OVERLAPPED::OffsetHigh = 0;
}
