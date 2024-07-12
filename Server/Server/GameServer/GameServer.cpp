#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>

// 예시 클래스
#include "AccountManager.h"
#include "UserManager.h"


// DeadLock

/*
데드락은 락이 두개 이상의 작업이 서로의 작업이 끝나기만을 기다리고 그래서 아무런 작업이 완료되지 않는 상태
lock(), unlock() 을 짝을 맞춰주거나 lock guard 를 사용한다고 해서 완벽히 데드락이 없다고 하지 못합니다. 

데드락이 걸리는 상황을 예시 들어보자면 
예시로 만든 AccountManager 객체와 UserManager 객체를 싱글톤 패턴으로 만들고 _mutex를 변수로 들고 있습니다. 
각각 GetAccount, GetUser 함수로 id 에 해당하는 Account, User 객체를 가져오도록 할겁니다. 
그리고 또 각각 AccountManager::ProcessLogin(), UserManager::ProcessSave(); 로 로그인코드와 게임저장 코드를 
만들고 서로의 Get 함수로 가져와 처리를 하려고 합니다. 

이 상태에서 두개의 쓰레드를 만들어 Process 함수들을 1000번씩 반복 호출하게 했습니다. 

두 쓰레드가 동시에 동작을 시작하면 서로 UserManager, AccountManager 에 락을 걸고 다시 Get 함수로 
서로의 함수안에서 다시 락을 걸겁니다. 그런데 1000번쯤 반복하다보면 중간에 락이 서로 걸려서 
오도 가도 못하게 되는 상황이 생기는데 이것이 데드락입니다. 

이 데드락을 해결하는 방법으로는 데드락이 걸릴만한 코드가 지나고 나서 락을 건다던가 
아니면 mutex에 번호를 매겨 우선순위를 준다던가 하는 방법들이 있습니다. 

또 데드락이 생기는 이유가 결국 락끼리의 사이클이 생겨서인데 락을 관리하는 매니저에서 이 사이클이 일어나는지를
추적하는 벙법도 있습니다. 

하지만 이 방법들도 결국 실수를 할 수 있고 그렇다보니 완벽한 해결방법이 아닙니다. 
*/

void Func1()
{
	for (int32 i = 0; i < 1000; i++)
	{
		UserManager::Instance()->ProcessSave();
	}
}

void Func2()
{
	for (int32 i = 0; i < 1000; i++)
	{
		AccountManager::Instance()->ProcessLogin();
	}
}

int main()
{
	{
		thread t1(Func1);
		thread t2(Func2);

		t1.join();
		t2.join();

		cout << "Jobs Done" << endl;
	}

	// 참고
	{
		mutex m1;
		mutex m2;

		std::lock(m1, m2);		// m1.lock(), m2.lock() 

		// adopt_lock : 이미 lock 상태니깐 나중에 소멸 될때 풀어줘라
		lock_guard<mutex> g1(m1, std::adopt_lock);
		lock_guard<mutex> g2(m2, std::adopt_lock);
	}
}
