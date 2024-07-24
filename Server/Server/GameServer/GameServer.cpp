#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>

#include "ConcurrentQueue.h"
#include "ConcurrentStack.h"

// Lock Free Stack	(스마트포인터 버전)

/*
팝 카운터를 사용하는 방식의 락프리 스택을 만들어 봤었습니다. 
그런데 꼭 이 방식으로만 구현할 수 있는것은 아닙니다. 팝 카운터는 shared_ptr의 참조 카운터와 비슷한 면이 있기때문에
이번에는 스마트 포인터를 활용한 방법으로 구현해보려고합니다. 

노드 struct 의 data, next 를 모두 shared_ptr 로 바꿔주었습니다. 

그리고 Push 에서 새로 생성한 노드를 _head에 추가할때 원자적으로 동작하기 위해 
_head.compare_exchange_weak 함수를 사용했었는데 이 함수는 atomic 의 멤버기 때문에 shared_ptr 이 된 _head는 사용할 수 없습니다.
대신 std::atomic_compare_exchange_weak 를 사용해도 거의 비슷하게 사용할 수 있습니다. 
_head의 멤버로 호출했던것 대신 첫번째 인자로 비교 대치할 _head를 주고 두번째 세번째 인자로 
expected, desired 를 넣어주면 됩니다. 

TryPop 에서도 역시 올드헤드를 꺼내고 atomic_compare_exchange_weak 로 체크후 _head 를 올드 헤드의 다음 노드로 바꿔줍니다.
그리고 올드헤드의 데이터를 반환해주면 되겠습니다. 

하지만 이 shared_ptr을 활용한 방법이 정말 락 프리한 방식으로 동작하고 있는지는 다른 이야기입니다. 
atomic_is_lock_free 라는 함수로 이 함수가 락프리 방식인지를 체크할 수 있는데 체크해보면 락프리 방식이 아니라고 나옵니다.

그러면 괜히 실습한 것이 됩니다. 

정말로 락프리한 다른 방법이 무엇인지를 다시 알아보겠습니다.
shared_ptr 이 아니라 직접 레퍼런스 카운팅을 구현하는 방식으로 만들겁니다. 

우선 노드의 구조가 실제 데이터, 다음에올 넥스트노드 여기에 추가로 internalCount 라는 atomic<int32> 타입 변수를 들고 있겠습니다. 
여기서 끝이 아니라 다시 이 노드를 들고 있을 구조체 CountedNodePtr 이라는 것도 만들것인데 
노드를 포인터로 들고 있을것이고 int32 타입의 externalCount 변수도 들고 있을겁니다. 

CountedNodePtr 에서 externalCount, Node 에서 internalCount 두가지 카운트를 가지고 있을 것이라는 겁니다. 

이 상태에서 Push를 만들어보면 
먼저 CountedNodePtr 을 하나 만들고 이게 들고 있을 Node 를 인자 value 를 데이터로 들고 있게끔 생성에 저장하고 
externalCount는 1이라는 값으로 주고 생성합니다. 
이어서 똑같이 새로 만든 노드의 넥스트 노드를 현재 헤드로 저장하고 CAS 를 통해 헤드를 새 노드로 이동합니다. 
노드를 만들때 externalCount 를 초기화 해주는 것 말고는 이전 락프리 Push와 로직이 비슷합니다. 

문제는 TryPop 입니다. 
TryPop 할때는 Pop할 올드헤드를 스택에서 분리하고 자신만 이 올드헤드를 참조하고 있거나 마지막으로 참조하던 
쓰레드는 이 헤드를 삭제하면서 그 데이터를 반환하는 함수입니다. 

먼저 CountNodePtr 타입의 올드헤드에 현재 헤드를 저장합니다.
이제 현재헤드와 올드헤드둘이 헤드가 가리키는 노드를 참조하고있으니 externalCount를 늘려줄건데
IncreaseCount 라는 함수로 따로 만들어 줬습니다. 

IncreaseCount함수에서는 또 올드헤드를 저장한 뉴올드헤드를 만들고 이 뉴 올드헤드의 externalCount를 1 증가시킵니다.
그리고 올드헤드와 현재헤드를 CAS로 비교, 교체를 원자적으로 하고 이게 성공한다면 뉴 올드헤드의 externalCount 를 
이제야 올드헤드에 저장합니다. 왜 이렇게 하냐면 올드헤드를 만들고 externalCount를 증가시키고 CAS를 하는 
이 과정사이에 다른 쓰레드들이 끼어들 수 있으니 CAS가 성공해야 externalCount를 증가시킬수 있습니다. 
IncreasCount로 externalCount를 증가 시켰다면 이 올드헤드의 노드가 실제 데이터가 있는지를 확인합니다. 
스택이 비어있다면 TryPop을 여기서 종료할 수 있기때문입니다.

올드헤드의 데이터가 유효하다면 실질적인 Pop에 들어가야합니다. 
현재 헤드와 올드헤드를 비교해 같다면 스택의 두번째 노드를 현재헤드가 가리키도록 CAS를 합니다.
이때 현재헤드와 올드헤드르 비교할때 이제는 externalCount 값까지 같아야 합니다. CAS에 성공했다면 
이제 데이터를 반활할 준비를 하면서 자신이 Pop하는 노드의 마지막 쓰레드인지를 확인후 맞다면 노드를 삭제해줍니다. 
이때 internalCount를 활용하는데 externalCount에 2를 뺀 값을 internalCount에 fetch_add 합니다. 
internalCount의 fetch_add 반환값은 연산 이전값이니 0과 externalCount에 2를 뺀값의 -를 곱하고 비교합니다.
만약 이 노드를 쓰레드 하나만 참조하고 있었다면 노드를 푸시 할때 externalCount가 1이되고 TryPop에서 IncreaseHeadCount를 하면서
2가 됩니다. 여기에 2를 빼고 그 값을 internalCount에 저장후 같은지 비교를하니 팝이된 노드를 삭제 할 수 있습니다. 

팝할 노드의 TryPop에 거의 동시에 들어온 쓰레드가 총 3명이었다면 externalCount는 4가 되었을겁니다. 
그러면 2를 뺀 값은 2 그리고 internalCount의 값은0 이니 가장처음 팝을 성공한 쓰레드는 노드를 삭제하지 않고 빠져나갑니다. 
이어서 들어온쓰레드는 internalCouint.fetch_add(-1) 이 1과 같은지를 체그하는데 
두번째 쓰레드는 fetch_add 반환값이 2, 세번째 쓰레드는 fetch_add 반환값이 1로 마지막 쓰레드인 세번째 쓰레드가
노드를 삭제하고 빠져나갑니다. 


이런 복잡한 락 프리 스택을 만들어보면서 느낄 수 있는것은 이 난이도와 복잡함에 비해 
그만큼의 성능이 뒤따르는가 입니다. 
락프리 프로그래밍이라는 이름이 아주 매력적인 성능상승을 기대할 수 있을것 같지만 결국은 락을 안쓴다 뿐이지 
아토믹적인 연산을 통해 경합상황이 생기는것은 똑같습니다. 오히려 락을 사용하면 스핀락처럼 락이 열리기를 기다리거나
이벤트를 통해 다음쓰레드가 동작할 준비가 되면 동작할 수 있지만 락프리 코드에서는 경합에서 밀리면 
로직을 처음부터 다시 실행해야합니다. 

그러므로 사실상 게임을 만드는데에는 락프리 프로그래밍은 필수가 아니고 그냥 멀티쓰레드에대해 알아보면서 겸사 겸사 
공부하는 주제입니다. 

*/


// 만들어본 Lock 기반 큐, 스택
LockQueue<int32> q;
LockFreeStack<int32> s;

// Lock 기반 테스트 함수
void Push()
{
	while (true)
	{
		int32 value = rand() % 100;
		s.Push(value);

		this_thread::sleep_for(10ms);
	}
}

void Pop()
{
	while (true)
	{
		auto data = s.TryPop();
		if (data != nullptr)
			cout << (*data) << endl;
	}
}

int main()
{
	// 기존 큐, 스택
	{
		thread t1(Push);
		thread t2(Pop);

		t1.join();
		t2.join();
	}
}
