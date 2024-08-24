#include "pch.h"
#include "IocpEvent.h"

/*--------------
	IocpEvent
---------------*/

IocpEvent::IocpEvent(EventType type) : _type(type)
{
	Init();
}

// �����ڿ��� ���� �ʰ� �� ���� ���ĸ� Ȥ�� �ٸ������� ���� ȣ���ϰ� ���� ���� �ֱ� ����
// OVERLAPPED�� ���� ������ 0���� �о��ִ°�, �� ���ΰ��� �ü������ �˾Ƽ� ����ϴ°��̱� ������ hEvent ����� �ǵ帱 ���� �����ϴ�. 
void IocpEvent::Init()
{
	OVERLAPPED::hEvent = 0;
	OVERLAPPED::Internal = 0;
	OVERLAPPED::InternalHigh = 0;
	OVERLAPPED::Offset = 0;
	OVERLAPPED::OffsetHigh = 0;
}
