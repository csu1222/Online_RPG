#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>

// Spin Lock

/*
스핀락은 락 대기를 계속 시도하는 락입니다. 게임프로그래머 면접에서 자주 나오는 주제 이기도 합니다. 
멀티쓰레드에 대한 이해도를 잘 알수 있는 주제이기 때문에 그렇습니다.

표준 mutex를 사용해 락가드를 통한 멀티스레드 테스트에서 
자체적으로 만든 스핀락 클래스로 교체하는 실습을 해보겠습니다. 

처음 생각해보고 bool 으로 락을 구현하려고 하면 일단 빌드와 실행은 되는데 값이 정상적으로 0이 나오진 않습니다. 
그냥 bool 타입이 아니라 volatile bool 을 사용해야 합니다. volatile 키워드를 사용하지 않은게 전부는 아니긴 합니다. 

volatile 키워드는 컴파일러에게 코드를 최적화 하지 말고 실행해달라고 하는것입니다. 
컴파일러가 판단해 의미없는 코드는 실제 실행때는 무시하고 컴파일을 하는데 그것을 그냥 코드가 적힌대로 전부 컴파일 해 달라는 것입니다. 

그런데 SpinLock::lock() 에서 _locked 를 체크해 무한 루프를 도는데 volatile 키워드를 안쓰면 _locked 를 체크하는게 의미 없다고 생각해서 
적힌대로 컴파일을 하지 않게됩니다. 

하지만 volatile 키워드를 적용해도 제대로 동작하지 않습니다. 

그러면 무엇이 문제일까요 

우리가 만든 구조의 SpinLock 에서는 우리가 보기에는 SpinLock::lock() 에서 while(_locked) 를 체크하고 _locked = true;
하는것이 한번에 일어나는 일같지망 프로그래밍에서, 어셈블리어에서 보면 이것은 더 세부적인 단계를 가지고 있고 이 작업이 멀티쓰레드 환경에서 
동작하면 동시에 락으로 들어오는 일이 생길 수 있습니다.

그래서 while(_locked) 를 체크하는 코드와 _locked = true; 로 설정하는 두 부분으로 나뉘어 있는데 여기를 한번에 아토믹하게 동작하게끔 
만들어 줘야합니다. 

atomic<bool> _locked 로 변경하면 이제 volatile 키워드는 필요 없어집니다. 
아토믹객체로 만들게 되면 CAS(Compare_And_Swap) 이라는 패턴을 사용할 수 있게 되는데 이 패턴의 함수는 언어마다 다르지만 
C++ atomic 에서는 compare_exchange_strong 이라는 메소드로 사용가능합니다. 

compare_exchange_strong 은 bool 을 반환하고 인자로 bool% _Expected, bool _desired 라는 인자를 받습니다. 
expected 를 false 로 주고 desired 를 ture 로 줘보겠습니다. 
이 코드가 어떤 의미인지 의사코드로 표현해보겠습니다. 

1. _locked 의 값과 expected 의 값을 비교합니다. 
2. expected 에 _locked 의 값을 넣어줍니다. 
3. 만약 1의 두 값이 같다면 desired 의 값을 _locked 에 넣어주고 return ture 를 합니다.
4. 1의 두 값이 같지 않다면 expected 에 _locked의 값을 넣어주고 return false 를 합니다. 

이 동작을 원자적으로 하게 되는겁니다. 

조금더 설명하자면 _locked 의 값이 expected 값와 같기를 기대하고 있는겁니다. 기대와 같이 _locked 의 값과 expected 이 값이 같다면 
desired 원하는 값으로 _locked 의 값을 바꿉니다. 

compare_exchange_strong 이 성공했다는 것은 _locked 의 원래 값이 false 여서 true 값으로 교체 되었다는 이야기입니다. 
이것은 처음 이 함수로 들어온 쓰레드가 락을 걸어 잠그는 상황입니다. 실패했다는것은 _locked 가 true 였다는 이야기이니깐 나중에 들어온 
쓰레드가 락이 풀리기 기다리는 상황입니다. 

하지만 조심해야하는 것이 compare_exchange_strong 이 실패를 해도 expected 값이 _locked 값으로 수정이 되어 버립니다. 
그래서 루프 안에서 expected 값을 원래의 초창기 값으로 바꿔줘야합니다. 

atomic<bool> _locked를 사용하고 compare_exchange_strong 을 사용하면 이제 제대로 sum 값이 0으로 나옵니다. 

스핀락의 기초적인 구조를 만든것입니다. 
사실 처음 구상한 구조는 맞지만 멀티쓰레드 환경에서의 처리를 위해 아토믹을 도입한것입니다. 

스핀락을 사용할만한 상황은 락이 얼마 안기다려도 되는 상황일때는 굳이 컨텍스트 스위칭 리소스를 사용하지 않아도 되는 장점이 있고 
다만 너무 락을 너무 오래걸리게 되면 싱글스레드에 준하는 성능으로 까지 떨어지는것이 문제입니다. 
*/

class SpinLock
{
public:
	// lock, unlock 을 소문자로 만들어야 lock_guard의 시그니처와 호환됩니다. 
	void lock()
	{
		// bool 변수를 사용할때 
		//while (_locked)
		//{

		//}

		//_locked = true;


		// CAS (Compare-And-Swap)

		bool expected = false;
		bool desired = true;

		while (_locked.compare_exchange_strong(expected, desired) == false)
		{
			expected = false;
		}
	}

	void unlock()
	{
		// bool 변수를 사용할때
		// _locked = false;

		// atomic<bool> 이니깐 그것을 알려줄겸 store 를 사용
		_locked.store(false);
	}

private:
	// 무작정 락을 만들어 보라면 bool 변수를 많이 사용합니다. 
	// volatile 키워드는 컴파일러에게 이 변수를 최적화 하지 말아 달라고 하는키워드 
	// volatile bool _locked = false;

	// atomic 을 사용하는 순간 volatile은 생각하지 않아도 됩니다. 
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
