#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>

// Thread Local Storage

/*
TLS 가 뭐냐면

지금까지 메모리를 사용할때 공용으로 사용하는 데이터는 객체를 할당하는 Heap 영역, static 변수나 함수들을 저장하는 Data 영역이 있었고 
각 함수들마다 로컬로 인자나 내부변수를 저장하는 스택 영역이 있었는데 
여기에 사실 TLS 라는 영역이 하나 더 있는것입니다.

이름에서 알 수 있듯이 쓰레드마다 로컬로 가지고 있는 메모리 영역입니다. 
모든 쓰레드마다 꼭 가지고 있어야 할 데이터를 이 TLS에 저장하면 됩니다. 

스택과 TLS 의 차이가 별로 없어 보이는데 엄밀히 보자면 스택은 함수의 로컬 메모리 이기 때문에 함수가 중간에 리턴되거나 
브레이크되면 그 안의 스택메모리는 다 날라가기 때문에 함수 진행이외의 용도로 사용하기는 불안정한 메모리 영역입니다. 
그래서 좀 더 쓰레드마다 안정적으로 가지고 있을만한 데이터를 저장할 수 있습니다. 

TLS 에서 가지고 있을만한 데이터는 나중에 네트워크 입출력을 할때 SendBuffer 같은걸 TLS 에 둬서 여기서 사용하는것과 쓰레드마다의 
아이디가 필요하다면 여기서 할당받아 사용하는 것 등이 있습니다. 
*/

// TLS를 사용하는 방법 (C++11 에 추가된 표준 방법)
// thread_local 타입 변수를 만들면 이 변수를 만든 쓰레드의 TLS 영역에 변수를 만들게 됩니다. 

// 예시로 쓰레드마다 직접 아이디 번호를 부여해보겠습니다. 
thread_local int32 LThreadId = 0;		

void ThreadMain(int32 threadId)
{
	LThreadId = threadId;

	while (true)
	{
		cout << "Hi I am Thread " << LThreadId << endl;
		this_thread::sleep_for(1s);
	}
}

int main()
{
	vector<thread> threads;

	for (int32 i = 0; i < 10; i++)
	{
		int32 threadId = i;
		threads.push_back(thread(ThreadMain, threadId));
	}

	for (thread& item : threads)
	{
		item.join();
	}
}
