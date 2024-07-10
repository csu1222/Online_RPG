#include "pch.h"
#include <iostream>
#include "CorePch.h"

// C++11 표준 쓰레드 라이브러리
#include <thread>

// 쓰레드에서 사용할 함수 1 
void HelloThread()
{
	cout << "Hello Thread" << endl;
}

// 쓰레드에서 사용할 함수 2
void HelloThread_2(int32 num)
{
	cout << num << endl;
}

int main()
{
	// 메인 쓰레드 에서 호출
	HelloThread();

	{
		// 쓰레드 t를 만들어 호출
		thread t(HelloThread);

		// 쓰레드객체는 따로 만들고 이후에 함수를 넣어줄 수도 있다
		thread t2;
		t2 = thread(HelloThread);

		t.join();								// 메인스레드가 t의 작업이 끝날때까지 기다림
		t2.join();
		int32 count = t.hardware_concurrency();	// 하드웨어 CPU 코어 개수 (정확하지 않을 수 있음)
		auto Id_1 = t.get_id();					// 쓰레드마다 부여되는 ID
		auto Id_2 = t2.get_id();
		// t.detach();							// std::thread 객체에서 실제 쓰레드를 분리 분리후에는 위의 함수들 사용불가 왠만해선 잘 사용안함
		bool result_1 = t.joinable();			// t라는 쓰레드의 유무나 아니면 .join() 가능여부를 확인 
		bool result_2 = t2.joinable();
	}

	{
		// joinable 함수는 쓰레드의 ID 가 할당이 됐는지를 체크하는 함수 
		// 정상적으로 쓰레드가 할당되었다는 뜻이므로 보통은 아래와 같이 사용하는게 정석
		thread t(HelloThread);
		if (t.joinable())
			t.join();
	}

	// 쓰레드 함수를 생성당시가 아니라 이후에 넣어줄 만한 상황은 
	// 이미 여러 쓰레드를 생성하고 이 후에 함수를 넣어주는 상황도 있습니다. 
	{
		vector<thread> threads;		// thread 의 벡터
		threads.resize(10);			// 10개의 thread를 생성

		threads[0] = thread(HelloThread);

		for (auto& item : threads)
			if (item.joinable())
				item.join();
			
	}

	// 인자가 있는 함수를 쓰레드에 주고 싶을때 
	{
		thread t(HelloThread_2, 10);	// 함수와 그 인자를 순서대로 인자로 준다 

		t.join();

		// 인자를 사용하는 함수의 쓰레드도 이렇게 사용가능 
		vector<thread> v_thread;
		
		for (int32 i; i < 10; i++)
		{
			v_thread.push_back(thread(HelloThread_2, i));
		}
		for (int32 i; i < 10; i++)
		{
			if (v_thread[i].joinable())
				v_thread[i].join();
		}
	}
}
