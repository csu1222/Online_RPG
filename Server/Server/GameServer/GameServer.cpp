#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>

// Condition Variable

/*
이전 이벤트 실습에서 사실 불안전한 부분이 있습니다. 
실습에서 Producer 함수는 10000ms 라는 시간마다 일감을 밀어넣었는데 이 속도는 너무 인위적인 속도이고 
실제 서비스에서는 한번에 일감이 몰릴 수 도 있고 일감이 한가할 때도 있습니다. 
만약 일감이 너무 많이 몰려서 사실상 매 프레임마다 q.push 를 해야하는 상황이라고 하겠습니다. 
그러면 생각하기로는 SetEvent도 매 프레임 호출이 되어서 Consumer 도 매 프레임 일감을 처리해주면서 적어도 0~1개 사이의 일감들만 
남아 있을것 같습니다. 

하지만 실제로 Consumer 에서 q.size() 를 출력하도록 하고 디버깅을 실행하면 q의 사이즈가 빠른 속도로 증가한다는걸 볼 수 있습니다. 
어떻게 보면 Event 로 쓰레드를 깨우는 부분과 락을 걸고 q.push, q.pop 을 하는 부분이 묶여있지 않기 때문에 멀티쓰레드 환경에서의 순서 틀어짐이 
발생할 수 있습니다. 

Producer 에서 SetEvent 로 signal을 주고 Consumer에서 WaitSingleObject에 들어와 쓰레드과 활성화 되는 순간과 이어서 락을 잡는 이 사이에는 
다른 멀티쓰레드가 개입할 여지가 있습니다. 그래서 이 사이에 다시 Producer 가 동작해 먼저 락을 잡고 push 를 할 수도 있습니다. 

물론 p.pop 을 할때 if 문이 아니라 while 문으로 한번 들어오면 q 안에 있는 모든 일감을 꺼낸다거나 하는 식으로 처리 할 수도 있지만 

중요한 점은 락과 이벤트는 별개라는 것입니다. 


이번 주제인 Condition Variable 입니다. 
표준으로 들어온 개념이기 때문에 곧바로 condition_variable 타입으로 사용할 수 있습니다. mutex에 포함된 클래스입니다. 
그렇다 보니 condition_variable 은 아무데나 사용할 수 없고 mutex와 병용해야 합니다. 
만약 자유롭게 사용하고 십다면 condition_variable 라이브러리를 include 하고 condition_variable_any 타입을 사용해야합니다.  

Condition Variable 조건변수는 커널 오브젝트가 아닌 유저레벨 오브젝트입니다. 

조건변수는 이벤트와 거의 비슷하게 동작을 하는데 다른점은 락과 짝을지어서 동작해야합니다. 

조건변수를 사용할때 notify를 보내는 쪽은 락을 잡고 코드를 진행한 후 락을 푼다음 notify를 합니다.
notify를 받는 쪽은 락을 먼저 걸고 cv.wait를 호출하는데 사용한 락과 동작할 조건을 함수로 줍니다. 
조건이 참이라면 이어서 코드를 실행하고 조건이 거짓이라면 락을 풀고 이 쓰레드는 대기상태로 갑니다. 

이때 락을 잠그고 풀어야 하기때문에 lock_guard 대신 unique_lock 을 사용합니다. 

wait 의 조건을 통과해야 다음 코드가 실행되기때문에 이어서 코드에서 if나 while 문으로 다시 조건을 판별하지 않아도 됩니다. 

생각해보면 notify_one 을 호출하는것 자체가 wait 에서 깨어날 조건에 부합한다면 코드를 진행하기 때문에 굳이 wait 에서 일어날 조건을 걸지 않아도 될것 같습니다. 
이런상황을 Spurious WakeUp 입니다. 공유 변수값을 수정하는것과 notify_one을 호출하는 것은 분리 되어 있기 때문에 이 사이에 다른 어떤 쓰레드에서 
공유 변수를 수정해 데이터를 비워버린다던가 내용물을 바꿔치기 한다면 cv.wait 로 깨어났지만 처리할 데이터가 없다고 나올 수 있습니다. 

또 한가지 궁금함은 notify_one 을 호출할때 락을 풀고 호출하는데 꼭 그래야 하는가 입니다. 
락을 잡은 상태에서 notify_one을 호출할 수 있기는하지만 권장되지 않는 방법입니다. 

락이 걸린상태에서 notify_one을 호출하면 어느쓰레드의 cv.wait가 깨어나 락을 잡고 조건을 확인하려고 하는데 이미 락이 잡힌 상태라서 제대로 동작하지 않습니다. 
*/

mutex m;
queue<int32> q;
HANDLE handle;

// 표준으로 사용할 수 있습니다.	mutex 라이브러리에 포함되어 mutex와 함깨 사용해야함
condition_variable cv;

// 자유롭게 사용하려면 이렇게 
//#include <condition_variable>
//condition_variable_any cva;

void Producer()
{
	while (true)
	{	
		// 1) 락을 잡고
		// 2) 공유 변수 값을 수정
		// 3) 락을 풀고
		// 4) 조건변수를 통해 다른 쓰레드에게 통지

		{
			unique_lock<mutex> lock(m);

			q.push(100);
		}

		cv.notify_one();	// wait 중인 쓰레드가 있으면 딱 한개를 깨운다
	}
}

void Consumer()
{
	while (true)
	{
		// 1) 락을 잡고
		// 2) 조건변수를 통해 wait를 합니다. 이때 탈출조건을 함수로 줄 수 있습니다. 
		// 2-1) 만약 조건을 만족한다 -> wait에서 빠져나와 이어서 코드를 진행 
		// 2-2) 조건을 만족하지 않는다 -> 락을 풀어주고 대기상태로 전환합니다. 
		//  이때 락을 풀어주어야 하기 때문에 락가드를 사용하지 않고 유니크락을 사용함

		unique_lock<mutex> lock(m);
		cv.wait(lock, []() { return q.empty() == false; });

		//while (q.empty() == false)		// cv.wait 에서 이미 조건을 체크하기 때문에 다시 조건을 체크할 필요가 없습니다. 
		{
			int32 item = q.front();
			q.pop();

			cout << item << endl;
		}
	}
}

int main()
{
	{
		thread t1(Producer);
		thread t2(Consumer);

		t1.join();
		t2.join();

	}
}
