#pragma once

/*----------------
	IocpObject
-----------------*/

// Completion Port �� ����� Ŭ������ ��ӹ��� Ŭ����
class IocpObject
{
public:
	virtual HANDLE GetHandle() abstract;
	virtual void Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) abstract;
	// IocpEvent �� � ��Ʈ��ũ �̺�Ʈ�� ����Ű������ ���մϴ�. 
};

/*--------------
	IocpCore
---------------*/

class IocpCore
{
public:
	IocpCore();
	~IocpCore();

	HANDLE		GetHandle() { return _iocpHandle; }	

	// ������ CP �� ����ϴ� �Լ�
	bool		Register(class IocpObject* iocpObject);
	// CP�� ���� �ϰ��� �����ϴ� �Լ�
	bool		Dispatch(uint32 timeoutMs = INFINITE);
private:
	HANDLE		_iocpHandle;
};


// TEMP
extern IocpCore GIocpCore;