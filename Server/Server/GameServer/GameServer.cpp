#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>	// 이벤트를 사용하기 위해 추가

// Event

/*
이번에는 이벤트를 활용한 락입니다. 
이벤트는 꼭 락뿐만아니라 다양한 부분에서 사용될 수 있습니다.

이벤트라는것은 화장실의 예시에서 화장실문이 잠겼을때 다른 직원에게 문이 열리면 알려달라고 부탁하고 자신은 자리로 가서 쉬는 방식입니다. 
여기서 직원이라고 예시들은것이 사실은 커널입니다. 

이벤트를 만들때 인자에 따라 두가지 이벤트가 될 수 있습니다 
Auto Reset Event, Manual Reset Event 입니다. 

이벤트는 쉽게 생각하면 불리언 타입 변수라고 볼 수 있습니다. true, false 두가지 상태를가지고 문이 잠긴다 열린다 를 표현하는 것입니다. 

락을 잠근 쓰레드와 락이 풀리길 기다리는 쓰레드 둘다 커널쪽에 있는 이벤트라고 하는 불리언 비슷한 변수를 체크하면서 
이 이벤트가 true인지 false 인지에 따라동작을 하는것입니다. 

이벤트를 사용하는 순서를 말해보면 
일단 이벤트를 만듭니다. 이벤트의 초기값은 false 입니다. 그러면 락을 기다리는 쓰레드에서는 이 이벤트를 참조하면서 true일때 실행하기로 하고 
슬립에 들어갑니다. 그러면 락을 걸고 있던 쓰레드는 동작이 끝나면 이벤트의 값을 true로 바꿔주고 나갑니다. 
그러면 이벤트를 참조하던 쓰레드가 깨어나 동작을 시작하는 개념입니다. 

밑의 예제에서 Producer 함수에서 일감을 밀어 넣고 Consumer 에서 일감을 처리하게 되는데 
Producer는 this_thread::sleep_for(10000ms) 를 호출해 10000ms 만큼 쉬었다가 일감을 밀어넣습니다. 이것은 실제 입력이 띄엄띄엄 온다는 
예를 들어서 만든 환경입니다. 하지만 Consumer는 매프레임마다 호출하면서 q에 일감이 있는지를 계속 체크해야합니다. 
실제 디버깅을 해서 cpu 점유율을보면 적지만 일정부분 점유를 하고 있습니다. 점유율이 적다고 해서 그냥 놔둬서는 큰 프로그램에서 쌓인 적은 점유율들이 
말썽을 일으킬겁니다. 

그래서 Consumer 같은 경우에는 좀 다른 방법을 사용해야합니다. 
이런 곳에 Event 를 사용해볼겁니다. 

::CreateEvent(bool 보안속성, bool 매뉴얼리셋여부, bool 초기값, LPCWSTR 이벤트의 이름); 
이런 시그니처를 가진 함수로 이벤트를 만들 수 있습니다. 
이벤트를 만드는것은 커널모드에서 만들어주는 함수이기 때문에 이런 이벤트를 커널 오브젝트라고도 부릅니다. 
반환은 HANDLE 타입을 반환하는데 이 핸들이라는것은 int와 같은 정수들이 들어있는데 아무 의미없는 정수는 아니고 
일종의 번호표라고 할 수 있습니다. 커널단에서 해당 번호표의 핸들을 지금 반환값을 가지고 온겁니다. 
이벤트가 꼭 하나만 있을거라는 보장이 없으니까 그 핸들의 값을 변수로 저장하는것입니다. 마치 포인터변수를 가지고 있는것 같습니다. 
핸들을 다 사용하면 ::CloseHandle로 닫아줘야합니다. 

핸들은 커널오브젝트라고 표현했습니다. 
커널 오브젝트는 커널모드에서 사용하는 오브젝트다 라는 뜻입니다. 말 그대로 입니다. 
공통적으로 가지고 있는 정보는 Usage Count 라고 해서 참조 카운트 같이 이 커널 오브젝트를 몇군대에서 사용하고 있는지
Signal / NonSignal 이라고 해서 bool 변수처럼 true, false 같은 역할을 합니다. 
이 두가지가 커널 오브젝트가 공통적으로 가지고 있는 정보이고 

지금 만든 Event 라는 커널오브젝트는 여기에 추가로 Auto Reset / Manual Reset 여부를 가지고 있습니다. 
이벤트는 커널 오브젝트중 가벼운 객체 축에 듭니다. 

Consumer 에서 이벤트를 기다릴때
::WaitSingleEvent(handle, INFINITE);
를 호출해줍니다. handle의 이벤트가 signal 인지를 주시하면서 signal 이 맞다면 다음 코드로 넘어갑니다. 
이때 스핀락처럼 계속 실행권을 들고 있으면서 기다리는게 아니라 signal이 켜졌을때 작업 스케줄러로 들어가 실행권을 얻어오는겁니다.

이벤트 오브젝트를 만들때 옵션으로 bManualReset 값을 FALSE 로 줬다면 AutoReset 이기 때문에 한번 WaitSingleEvent 가 통과되면 
자동으로 NonSignal 상태가 되고 ManualReset 상태라면 직접 ResetEvent(handle); 로 NonSignal 로 수정해줘야합니다. 

테스트를 해보면 동작자체가 바뀌지는 않았지만 
CPU 점유율이 조금있던것 마저 없어졌다는걸 알 수 있습니다. 


추가로 커널 오브젝트의 특징한가지를 더 알아보자면 
커널 오브젝트는 다른 프로그램끼리도 동기화를 할 수 있습니다. 유저모드 오브젝트는 각 프로그램안에서만 유효한 오브젝트이지만
커널 오브젝트는 아예 이 컴퓨터의 오브젝트이기 때문에 다수의 프로그램에서도 가져다 사용할 수 있는겁니다. 

*/

mutex m;
queue<int32> q;
HANDLE handle;

// 무언가 일을 큐에 밀어넣는 함수 예를 들어서 게임 컨텐츠나 네트워크 패킷을 계속 JobQueue에 밀어넣는 상황
void Producer()
{
	while (true)
	{
		{
			// 공용데이터를 건드릴것이니 락을 걸고 동작
			unique_lock<mutex> lock(m);

			q.push(100);
		}

		// 이벤트 객체를 signal 상태로 수정한다는 함수
		::SetEvent(handle);

		// 데이터가 10000ms 마다 들어온다고 가정 
		this_thread::sleep_for(10000ms);
	}
}

// Queue에 들어온 작업들을 처리하는 함수 
// 여기서는 Queue에 얼마만에 한번씩 데이터가 들어오는지 알수 없어서 계속 시도를 합니다.
void Consumer()
{
	while (true)
	{
		// 핸들의 이벤트를 주시하면서 INFINITE의 시간만큼 기다립니다. 
		::WaitForSingleObject(handle, INFINITE);
		// ::ResetEvent(handle);	// 이벤트를 만들때 bManualReset 값을 TRUE로 줬으면 직접 리셋해줘야합니다. 

		unique_lock<mutex> lock(m);
		if (q.empty() == false)
		{
			int32 item = q.front();
			q.pop();

			cout << item << endl;
		}
	}
}

int main()
{
	handle = ::CreateEvent(NULL/*보안속성*/, FALSE/*bManualReset*/, FALSE/*bInitialState*/, NULL/*Ipname*/);
	{
		thread t1(Producer);
		thread t2(Consumer);

		t1.join();
		t2.join();

		::CloseHandle(handle);
	}

}
