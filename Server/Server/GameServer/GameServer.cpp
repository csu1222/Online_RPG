#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>

// 멀티쓰레드 환경에서 공유 메모리를 다룰때의 문제

#include <atomic>

int32 sum = 0;
atomic<int32> a_sum = 0;

// 일반 함수들
void Add()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		sum++;
	}
}

void Sub()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		sum--;
	}
}

// 아토믹 변수를 활용한 함수들
void A_Add()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		a_sum.fetch_add(1);
	}
}

void A_Sub()
{
	for (int32 i = 0; i < 100'000; i++)
	{
		a_sum.fetch_add(-1);
	}
}

int main()
{
	// 메인쓰레드에서 Add, Sub 을 같은 횟수 호출하면 당연히 총합 0 
	{
		Add();
		Sub();

		cout << sum << endl;
	}

	// 쓰레드를 만들어 멀티 쓰레드 환경에서 다시 테스트
	{
		thread t1(Add);
		thread t2(Sub);

		t1.join();
		t2.join();

		cout << sum << endl;
		// 결과는 0이 아닌 엉뚱한 값이 나옵니다. 
	}

	// 왜 이상한 값이 도출될까?
	// 공유데이터와 관련된 문제입니다. 
	// 우선 공유데이터는 메모리중 힙영역, 데이터 영역 메모리는 모든 쓰레드가 공유하는 공유메모리 영역입니다. 
	// 단순한 ++, -- 연산도 사실 어셈블리어로 보면 한가지 명령어로 이루어져 있지 않습니다. 
	// ++ 을 예로 들면 sum 주소의 값을 레지스터로 가져오고, 그 값을 1증가시키고 다시 sum 위치로 가져다 놓습니다.
	// 이 과정을 멀티쓰레드가 동시다발적으로 진행합니다. 이 동작 사이사이에 여러 쓰레드들이 접근, 수정을 하다 보니 예상치 못한 동작이 되는겁니다. 

	// 멀티쓰레드 환경에서 이 문제를 해결하기 위한 몇가지 방법이 있는데 그 중 하나가 
	// atomic 입니다. 
	// atom 원자라는 이름 처럼 atomic 변수는 한번에 모든 코드가 진행되거나 아니면 아예 진행이 되지 않도록합니다. 

	{
		thread t1(A_Add);
		thread t2(A_Sub);

		t1.join();
		t2.join();

		cout << a_sum << endl;

		// 아토믹은 멀티쓰레드에서 공유 메모리를 안전하게 수정하는 방법중 하나지만 이것은 생각보다 성능이 좋지 못합니다.
		// 동시에 하나의 아토믹만 작업이 가능하다 보니 병목현상이 일어나고 멀티쓰레드를 사용하는 의미가 퇴색 됩니다.
	}
}
