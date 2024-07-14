#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>

// Sleep 

/*
락의 종류중에서 이제 두번째로 랜덤으로 체크를 하는 락을 다룰겁니다. 
그것을 위해 먼저 Sleep 을 알아야합니다.	

멀티쓰레드에서는 쓰레드라는 일꾼들과 그 쓰레드에 빙의하는 코어들이 있었습니다. 
커널모드에 있는 코어에서 유저모드에 있는 쓰레드에 하나씩 빙의되어 코드를 실행하고 있습니다. 

또 한가지 알아야 할 개념이 스케줄링 입니다. 이게 무엇이냐면 유저모드에서 여러 일감들이 있을건데 
일감들을 어떤 순서로 처리할건지 순서가 필요할겁니다. 어떤 프로그램이 더 중요한지 같은걸 고려해 순서를 정하게 될건데
스케줄러가 프로그램들을 실행할때 각 프로그램을 실행하는 쓰레드에 일정 시간을 동작할 수 있도록 정해 줄 수 있습니다. 
하나의 쓰레드에 빙의되었다고 이 쓰레드가 가진 모든 일을 다 처리한 후 다음 쓰레드에 빙의되는게 아니라 일정시간동안 처리하다가 
다음 쓰레드로 넘어가는 식입니다. 

콘솔 함수같은 것은 유저모드에서 다 처리가능한게 아니라서 시스템 콜이라는것을 요청하면 커널모드로가서 콘솔에 로그를 찍어주고 다시 
유저모드의 쓰레드로 돌아와 다음 코드를 처리하게 됩니다. 어떤 일을 하기위해 시스템콜을 호출하거나 아니면 이번에 배울 Sleep 을 사용하면 
쓰레드의 실행권을 포기하게 됩니다. 

이 Sleep 으로 실행권을 포기하는 것이 화장실앞에서 일단 자리로 돌아가는 걸로 비유할 수 있습니다. 

사실 윈도우즈 자체에서 실행하는 프로세스만 해도 한두개가 아닙니다. 
이 많은 프로세스들을 작업 스케줄러 라고 하는 Queue 에 넣어두고 컴퓨터의 코어가 여유가 생길때 하나씩 빙의해 실행을하게됩니다. 
실행중에 입출력또는 Sleep 같은 명령으로 대기 상태로 들어가고 일정시간이 지나던지 아니면 어떤 이벤트에 따라 다시 작업 스케줄러로 돌아가 
코어가 할당되기를 기다리게 됩니다. 

이번 실습에서 해볼건 단순히 sleep 함수를 사용하기 뿐이지만 그 원리는 이런 식으로 돌아갑니다. 

이전에 만들었던 SpinLock 은 락을 기다리는 쓰레드가 계속 유저모드에 남아 시스템이 허락하는 가장 긴 시간까지 락이 풀리기를 기다리는 방식입니다. 
락이 금방금방 풀리는 작업이라면 오히려 효율이 좋지만 그렇지 않다면 병목현상이 심한 락이었습니다. 

추가해볼것은 this_thread::sleep_for, this_thread::yield 입니다. 
sleep_for는 인자로 std::chrono::milliseconds()로 슬립할 시간을 줄 수 있고 100ms 이런식으로도 표현할 수 있습니다.
yield는 그냥 양보를 하는 함수로 0ms를 준 sleep_for 와 사실상 동일합니다. 

여기서 양보를 한다 슬립을 한다는것은 인자로 준 시간이 지나고 바로 다시 쓰레드가 동작한다는것이 아니라
그 시간이 지나고 작업 스케줄러에 등록이 된다는 뜻입니다. 
*/

class SpinLock
{
public:
	void lock()
	{
		bool expected = false;
		bool desired = true;

		while (_locked.compare_exchange_strong(expected, desired) == false)
		{
			expected = false;

			// 이 코드를 실행할때 부터 100 밀리초만큼 잠듭니다. 
			// this_thread::sleep_for(std::chrono::milliseconds(100));

			this_thread::sleep_for(100ms); // 밀리초를 이렇게 표현할 수도 있습니다. 

			// yield 는 양보한다라는 의미가 있듯이 일단 이 쓰레드의 실행권을 넘기는 함수입니다. 사실상 0ms 로 sleep_for 를 호출한것과 같습니다. 
			// this_thread::yield();
		}
	}

	void unlock()
	{
		_locked.store(false);
	}

private:
	atomic<bool> _locked = false;
};


int32 sum = 0;
mutex m;
SpinLock spinLock;

void Add()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		//lock_guard<mutex> g(m);
		lock_guard<SpinLock> g(spinLock);
		sum++;
	}
}

void Sub()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		//lock_guard<mutex> g(m);
		lock_guard<SpinLock> g(spinLock);
		sum--;
	}
}

int main()
{
	{
		thread t1(Add);
		thread t2(Sub);

		t1.join();
		t2.join();

		cout << sum << endl;
	}

}
