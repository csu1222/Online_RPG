#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
#include <windows.h>
#include <future>

// 메모리 모델 

/*
캐시와 CPU 파이프라인이 이번 주제 메모리 모델을 학습하기 위한 준비였습니다. 

C++ 이라는 오래된 프로그래밍 언어에서도 모던 C++ 이라고 부르기 시작하는 C++11 에서 많은 추가내용이 있었지만 
그 중에서도 메모리 모델이라는 개념이 확립되었습니다. 

잠깐 멀티쓰레드 프로그래밍에 대해 복습을 해보자면 
여러 쓰레드가 동시에 동작하는 프로그래밍이 멀티쓰레드 프로그래밍이고 이때 싱글쓰레드에서는 문제되지 않았던 코드가 
문제가 되기 시작하는데 공유 메모리에 접근해 수정을 하는 순간 문제가 일어납니다. 
공유 데이터를 수정할때 C++에서는 한줄의 코드로 작성되었지만 어셈블리언어로 보면 데이터를 레지스터로 가져오고 수정하고 다시 가져다 놓는 3단계를 거칩니다. 
이 사이에 다른 쓰레드가 접근하는것이 문제 였습니다.

이걸 해결하기 위해서 락을 걸어서 공유메모리에 한번에 한쓰레드만 접근하도록 막는다던가 
atomic 객체를 통해 원자적으로 동작하는 변수를 만들었어야 합니다. 

C++11 에서 보증하는 하나의 법칙이 있는데 atomic 연산에 한해서는 모든 쓰레드가 동익 객체에 대해서 동일한 수정 순서를 관찰한다는것입니다. 

동일 객체, 동일 순서라는 단어가 중요한데 

먼저 동일 수정 순서에 대해 설명 해보자면 atomic 변수를 가지고 .store() 함수를 통해 멀티쓰레드에서 값을 수정한다고 해보겠습니다. 
이러면 어떤 쓰레드가 먼저 도착하는지에 따라 먼저 접근한 쓰레드의 작업이 다 완료되고 그 다음 작업이 진행될것입니다. 

이 상황에서 또 다른 제 3의 쓰레드에서 수정하던 atomic 변수를 루프를 돌면서 계속 관찰을 한다고 해보겠습니다. 

캐시의 내용을 떠올려보면 수정을 막 진행하는동안 실제 atomic 변수의 주소의 값이 그때그때 수정되는것인지 아니면 
캐시에 저장된 데이터가 수정되는것인지 확신할 수 없습니다. 

이때 보장이 되는것이 동일 객체에 대해 동일한 수정 순서가 관찰되는게 보장이 됩니다. 

멀티쓰레드 환경에서 atomic 변수의 값이 0, 2, 1, 5 라는 순서로 수정이 되었다고 하겠습니다. 
이 atomic 변수를 관찰하는 쓰레드 에서는 변수의 값이 동시에 관찰이 된다고는 보장할 수 없지만 
결국 늦게 수정이 된다고 하더라도 0, 2, 1, 5 라는 순서로 값이 수정된다는 사실만은 보장 할 수 있다는것입니다. 

결국 멀티쓰레드 환경에서 atomic 연산에서는 모든 메모리가 동시에 수정이 된다고는 할 수 없지만 
수정되는 순서는 늦게라도 동일하게 수정이 될것입니다. 

여기에 더해서 atomic 연산이라는것은 꼭 atomic 객체의 연산을 뜻하지는 않습니다. 
이름 그대로 원자적인 연산 더이상 쪼개질 수 없는 연산에 모두 해당되는 법칙입니다. 

int64 num; 

이라는 변수에 1 이라는 값을 저장할때 최근의 대부분 컴퓨터에서는 이 동작이 원자적으로 동작할 겁니다. 
왠만해서는 64bit 주소체계를 사용하기 때문에 해당 메모리에 바로 접근해 수정을 하기 때문인데 
예전에 사용하던 32bit 주소체계를 사용하는 컴퓨터는 상위 32bit 주소에 접근해 수정하고 하위 32bit에 다시 접근해 수정할것입니다. 

즉, 컴퓨터의 환경에 따라 같은 코드도 원자적으로 동작할 수 있고 동작하지 않을 수도 있습니다. 

참고로 어떤 타입의 변수가 자신의 PC 환경에서 원자적으로 처리하는지는 
해당 변수를 atomic 객체로 만들고 .is_lock_free() 함수를 호출해봐서 그 값이 true 면 원래 원자적으로 처리할 수 있는 타입이라는것이고 
false 라면 atomic 객체로 만들지 않았으면 원자적으로 처리하지 못하는 타입이라는 것입니다. 


또 한가지 강조해야할 점은 위의 법칙이 동일 객체에 대해서만 성립한다는것입니다. 
만약 다수의 변수가 atomic 연산을 한다고 해도 각 변수의 수정 순서는 보장 할 수 없습니다. 

그렇다 보니 CPU 파이프라인 때 알아봤던 문제인 가시성과 코드 재배치 문제를 atomic 연산으로 해결 할 수 없습니다. 
가시성은 각 쓰레드끼리는 서로를 관찰 할 수 없다는 것이었고 코드 재배치의 문제는 여러 코드의 순서가 컴파일러 혹은 CPU에 의해 
재배칠 될 수도 있아는 것이었습니다. 


추가적으로 지금까지 atomic 객체의 값을 수정할때 .store 함수를 사용하고 있었는데 
더욱 정확히는 
atomic객체.store(수정할 값, 수정 정책); 을 뜻합니다. 뒤의 인자를 생략하면 
memory_order::memory_order_seq_cst 를 주고 있는것입니다. 

이 메모리 수정 정책이 이번 시간의 주제 입니다.

이 정책에 따라서 어떤 정책을 사용하면 메모리 가시성과 코드 재배치가 해결이 되고, 어떤 정책은 해결이 안되고 합니다. 


Memory Model(정책)
1) Sequentially Consistent	(seq_cst)
2) Acquire-Release			(consume, acquire, release, acq_rel)
3) Relaxed					(relaxed)

이렇게 크게 3가지 정책으로 분류 할 수 있습니다. 

여기서 또 좀 더 중요하게 봐야할 정책은 seq_cst, acquire, release, relaxed 4개 입니다. 

1) seq_cst : 가장 엄격, 컴파일러 최적화 여지 적고 직관적 아래 실습에서 사실 코드를 작성한 순서와 가시성이 유지 됩니다. 

2) acquire-release : 딱 중간 정도 입니다. 
	release 명령 이전의 메모리 명령들이 해당 명령 이후로 재배치 되는것을 금지 
	그리고 acquire 로 같은 변수를 읽은 쓰레드가 있다면 
	release 이전의 명령들이 -> acquire 하는 순간에 관찰가능합니다. 

3) relaxed : 자유롭다 컴파일러의 최적화 여지가 많고 직관적이지 않음 아래 실습에서 가시성도 보장이 되지않고 코드 재배치도 일어날 수 있습니다. 

보통 atomic 을 사용할때 아무런 정책을 정하지 않으면 기본적으로 seq_cst 정책을 사용해 알아서 엄격하게 동작 하게 되고 사실 대부분의 경우 
이렇게 사용하게 될것입니다. 

그리고 인텔, AMD CPU의 경우 애당초 순차적 일관성을 보장합니다. 
seq_cst 를 써도 별다른 부담이 없습니다. 

다만 ARM CPU의 경우는 꽤 차이가 있다고 합니다. 

추가로 acquire-release 같은 메모리 배리어를 사용하려면 꼭 atomic 객체를 활용해야 하냐면 꼭 그렇지는 않고 

std::atomic_thread_fence(memory_order::memory_order_release);
std::atomic_thread_fence(memory_order::memory_order_acquire);

이렇게도 메모리 배리어를 사용할 수 있습니다. 
*/

atomic<bool> ready;
int32 value;

void Producer()
{
	value = 10;

	ready.store(true, memory_order::memory_order_seq_cst);
}

void Consumer()
{
	while (ready.load(memory_order::memory_order_seq_cst) == false)
		;

	cout << value << endl;
}

int main()
{
	{
		// atomic 복습
		atomic<bool> flag = false;

		{
			//flag.is_lock_free(); // 이 멤버함수로 flag 라는 변수가 이 환경에서 그냥 atomic 하게 동작하는지를 체크 

			// flag가 atomic 객체라는것을 한눈에 알아보기 위함 
			// flag = ture;
			flag.store(true, memory_order::memory_order_seq_cst);

			bool val = flag.load(memory_order::memory_order_seq_cst);
		}

		// 이전 flag 값을 prev에 넣고 flag 값을 수정
		{
			// 이렇게 값을 교환하는것은 코드 재배치를 당할 수도 있습니다. 
			//bool prev = flag;
			//flag = true;

			// 대신 exchage를 사용합니다. 
			bool prev = flag.exchange(true);
			// exchange는 인자의 값으로 수정되고 반한값은 이전에 들고 있던 값을 넘깁니다. 
		}

		// CAS (Compare And Swap) 조건부 수정
		{
			bool expected = false;
			bool desired = true;
			flag.compare_exchange_strong(expected, desired);
			// 이 compare_exchange_strong 를 의사코드로 표현하면 
			// 1. flag의 값이 expected 와 같다면?
			// 2. flag의 값을 desired 값으로 바꾸고 true 리턴
			// 3. flag갑과 expected 의 값이 같지 않다면?
			// 4. expected의 값을 flag 값으로 바꾸고 false 리턴

			// 여기에 compare_exchange_strong 의 시그니처를 다시 보면 생략된 마지막 인자로 memory_order 가 있습니다.
		}
	}

	{
		// 메모리 정책 실습
		ready = false;
		value = 0;
		thread t1(Producer);
		thread t2(Consumer);
		t1.join();
		t2.join();
	}
}
