#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>	// C++ 11 표준 락은 mutex

// Lock 

vector<int32> v;
mutex m;

// LockGuard (RAII)
template<typename T>
class LockGuard
{
public:
	LockGuard(T& m)
	{
		_mutex = &m;
		_mutex->lock();
	}

	~LockGuard()
	{
		_mutex->unlock();
	}

private:
	T* _mutex;
};

// v 에 만개의 숫자를 푸시하는 함수 
void Push()
{
	for (int32 i = 0; i < 10000; i++)
	{
		v.push_back(i);
	}
}

void LockedPush()
{
	for (int32 i = 0; i < 10000; i++)
	{
		m.lock();		// 자물쇠 잠그기

		v.push_back(i);

		m.unlock();		// 자물쇠 풀기 
	}
}

void LGPush()
{
	for (int32 i = 0; i < 10000; i++)
	{
		LockGuard<mutex> lockGuard(m);

		v.push_back(i);

		if (i == 5000)
		{
			break;
		}
	}
}

int main()
{
	// 멀티쓰레드 환경에서 공유 데이터 수정
	{
		//thread t1(Push);
		//thread t2(Push);

		//t1.join();
		//t2.join();

		//cout << v.size() << endl;

		// 하지만 이 코드는 크래시가 납니다. 
		// 기존 C++ 컨테이너는 모두 멀티쓰레드 환경에서 동작하지 못한다고 생각하면 됩니다. 
		// 그 이유를 vector 의 동작 원리로 알아보면 
		// 동적배열은 현재 배열이 꽉 차면 다시 더 큰 영역을 할당받아 다시 배열을 사용합니다. 
		// 이 과정안에서 멀티쓰레드는 이 과정이 끝나던 말던 중간에 알아서 진행을 하기 때문에 이미 해제된 메모리를 
		// 참조, 수정하고 또 더블 프리를 하면서 크래시가 납니다. 
	}

	// 벡터에 미리 reserve로 공간을 마련했다면?
	{
		v.reserve(20000);

		thread t1(Push);
		thread t2(Push);

		t1.join();
		t2.join();

		cout << v.size() << endl;

		// 크래시는 안나지만 정확히 2만이라는 숫자는 나오지 않습니다. 
		// 오히려 크래시가 나지 않아서 버그를 못잡으면 더욱 나쁜 상황입니다.
	}

	v.clear();	// 테스트 한 v를 밀어주기

	// vector를 atomic 으로 사용하면 어떨까?
	{
		//atomic<vector<int32>> a;

		// 아토믹은 일반적인 데이터 타입에서 사용가능하고 벡터 같은 컨테이너에서는 벡터의 기능을 쓸 수 없습니다.
	}

	// 그러면 vector 같은 컨테이너는 멀티쓰레드 환경에서 사용하지 못하는건가?
	// 답은 Lock 입니다. 
	{
		thread t1(LockedPush);
		thread t2(LockedPush);

		t1.join();
		t2.join();

		cout << v.size() << endl;

		// 이러면 의도한대로 v 의 사이즈가 2만이 됩니다. 
		// 하지만 lock은 함수에 하나의 쓰레드만 들어오게끔 하는 기능이다 보니 
		// 멀티쓰레드의 이점을 잃어버리고 싱글쓰레드의 속도 밖에 못냅니다. 
	}

	v.clear();

	// 락의 주의점 상호배타적(Mutual Exclusive)
	// 표준 mutex는 재귀적으로 락을 걸 수 없습니다. 
	{
		for (int32 i = 0; i < 10000; i++)
		{
			m.lock();		// 자물쇠 잠그기
			//m.lock();

			v.push_back(i);

			m.unlock();		// 자물쇠 풀기 
			//m.unlock();
		}
		// 이 코드가 크래시가 납니다.
		// 굳이 락을 재귀적으로 잡을 이유가 있을까 싶긴 하지만 
		// 나중에 코드가 복잡해지면 함수내에서 다른 함수를 호출하다가 상위 함수에서 락을 잡았다가 
		// 안에서 호출한 함수에서 다시 락을 잡을 수 있습니다. 
	}

	// 락을 걸고 안풀어주는 상황도 있을겁니다. 
	// 이러면 앞으로 계속 다른 쓰레드들은 접근을 못하게 되는 상황이 됩니다.
	// 이런 초보적인 실수를 누가 하는가 싶을 수 있는데 
	// 역시 코드가 복잡해지면 락을 잡고 함수코드를 진행하는 순간 어떤 예외체크를 하다 break로 함수를 빠져나가면 unlock() 까지 해주지 않고 
	// 함수를 벗어나버립니다. 

	// 아무리 꼼꼼히 락을 풀어준다고 해도 결국은 실수를 할 수 밖에 없습니다. 
	
	// RAII (Resource Acquisition Is Initialization)
	// 이런 패턴이 있습니다. 이 패턴이 하고자 하는 바는 어떤 객체의 생성자에서 락을 잠그고 
	// 소멸자에서 락을 풀도록 하는 것입니다. 그리고 이 객체를 락을 걸고자 하는 함수에 만들어줍니다. 
	{
		thread t(LGPush);

		cout << v.size() << endl;

		// 위에서 예시로 LockGuard 를 만들었지만 표준에서도 당연히 있습니다. 
		{
			std::lock_guard<mutex> guard(m);
		}

		// lock_guard 말고 비슷한 기능이 하나 더 있습니다. 

		unique_lock<std::mutex> uniqueLock(m, std::defer_lock);
		uniqueLock.lock();
		// 다른 점은 unique_lock 객체를 만드는 순간 락이 잠기는게 아니라 명시적으로 잠근 이후로 동작합니다. 
		// 두번째 인자로 락을 잠그는 시점을 조절 할 수 있습니다. 
	}
}
