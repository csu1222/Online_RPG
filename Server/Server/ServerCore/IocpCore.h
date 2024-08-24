#pragma once

/*----------------
	IocpObject
-----------------*/

// Completion Port 에 등록할 클래스가 상속받을 클래스
class IocpObject
{
public:
	virtual HANDLE GetHandle() abstract;
	virtual void Dispatch(class IocpEvent* iocpEvent, int32 numOfBytes = 0) abstract;
	// IocpEvent 는 어떤 네트워크 이벤트를 가리키는지를 뜻합니다. 
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

	// 소켓을 CP 에 등록하는 함수
	bool		Register(class IocpObject* iocpObject);
	// CP에 들어온 일감을 관찰하는 함수
	bool		Dispatch(uint32 timeoutMs = INFINITE);
private:
	HANDLE		_iocpHandle;
};


// TEMP
extern IocpCore GIocpCore;