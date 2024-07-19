#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>

// 추가한 Lock 기반 Queue, Stack
#include "ConcurrentQueue.h"
#include "ConcurrentStack.h"

// Lock 기반의 Stack, Queue 만들어 보기 

/*
기존 싱글쓰레드 환경에서 사용하던 기존 Queue, Stack 을 멀티 쓰레드환경에서 사용해보자면
아래의 PushNormal, PopNormal 을 쓰레드 t1, t2 에 줘서 실행했습니다. 
언젠간 공유 메모리인 q 를 동시에 접근하면서 크래시가 나게 됩니다. 

그래서 당연히 여기에 mutex로 락을 걸어 사용하는것이 멀티쓰레드 환경에서 사용법일겁니다. 

그런데 자주 사용할 Queue, Stack 이라는 컨테이너 자체를 멀티쓰레드 환경에서 동작할 수 있으면 좋겠습니다.

새 클래스 ConcurrentQueue, ConcurrentStack 를 추가해보겠습니다. 
LockQueue, LockStack 의 멤버 함수의 Push, TryPop, WaitPop 자체 내부에서 각각 락을 잡아주는 방식으로 만들었습니다.
이렇게 만들면 락을 세부적으로 잡고 풀고 하기 때문에 그만큼 데드락 상황에 빠지는 확률을 줄여줍니다. 
*/

// 기존 큐, 스택 
queue<int32> q;
stack<int32> s;

// 만들어본 Lock 기반 큐, 스택
LockQueue<int32> lockQueue;
LockStack<int32> lockStack;

void PushNomal()
{
	while (true)
	{
		int32 value = rand() % 100;
		q.push(value);

		this_thread::sleep_for(10ms);
	}
}

void PopNormal()
{
	while (true)
	{
		if (q.empty())
			continue;

		int32 data = q.front();

		q.pop();

		cout << data << endl;
	}
}

// Lock 기반 테스트 함수
void PushLock()
{
	while (true)
	{
		int32 value = rand() % 100;
		lockQueue.Push(value);

		this_thread::sleep_for(10ms);
	}
}

void PopLock()
{
	while (true)
	{
		int32 data = 0;

		if (lockQueue.TryPop(OUT data))
			cout << data << endl;
	}
}

int main()
{
	// 기존 큐, 스택
	{
		thread t1(PushNomal);
		thread t2(PopNormal);

		t1.join();
		t2.join();
	}
}
