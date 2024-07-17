#include "pch.h"
#include <iostream>
#include "CorePch.h"
#include <thread>
#include <atomic>
#include <mutex>
// 추가
#include <future>

// Future

/*
조건변수의 경우는 Queue에 일감을 밀어넣고 그 일감을 꺼내 처리하는 작업에 아주 잘 어울리는 클래스였습니다. 

조금 더 가벼운 작업에 사용할 수 있는 Future 클래스에 대해 알아볼겁니다. 

먼저 동기화 방식이라는 것을 알아야 하는데 동기화 방식이라는것는 프로그램이 진행되면서 처리되는 코드들이 있을겁니다. 
이 코드의 진행이 이 쓰레드 안에서 단 한가지 뿐이라 함수가 호출된다면 그 함수의 모든 코드를 처리하고 나서 나와야 다시 원래의 진행 순서로 
가는것입니다. 
원래 처음 배우는 프로그래밍에서 동기화 방식은 아주 당연해 보입니다. 
하지만 어떤 함수의 처리가 100초나 걸리는 함수였다면 함수가 처리 될 때까지 코드 진행이 멈추기도 할겁니다. 

비동기 방식으로 처리를 하면 오래걸리는 함수를 병렬적으로 진행하고 이어서 코드를 진행 할 수 있을겁니다. 
배운 내용중에서는 쓰레드를 하나 만들어 오래걸리는 함수를 시키고 메인 쓰레드는 나름의 코드를 진행하는것일겁니다. 

하지만 일꾼 쓰레드의 함수가 끝나 join() 까지 도달하면 쓰레드 내부의 데이터는 다 날라갔을 테니 
따로 전역 변수 같은걸 만들어 여기에 저장하는것까지 해야 그 결과물을 알 수 있을겁니다. 
그래도 공용데이터를 다룬다는것 자체가 불편합니다. 락을 걸어야 할 수도 있기 때문이도 또 쓰레드들이 하나만 있을것이 아니고 
그 안에서 필요한 정보들도 한둘이 아닐텐데 각각 공용데이터로 변수를 만들어 받아줘야하는것도 실수위험이나 가독성에 문제가 있습니다. 

거기에 쓰레드를 새로 하나 만드는 동작은 생각보다 무거운 작업이기 때문에 좀 더 오래 사용할 일감에 해주는게 좋고 
간단하게 단기 알바 같은 일감은 이번 시간 주제인 Future 객체를 사용하면 좋겠습니다. 

future 객체를 사용하는 방법은 세가지가 있는데 std::async 로 future 객체를 생성하는 방법(async, deffered 두가지 옵션이 있습니다.)
그리고 promise 객체와 future 객체를 연동하고 promise 객체를 다른 쓰레드에서 실행한후 그 값을 future 객체에서 가져오는경우
그리고 pakaged_task를 만들때 실행할 함수를 인자로 주고 다른 쓰레드에서 그 pakaged_task를 처리하는 함수와 pakaged_task 객체를 
같이 넘겨주고 나중에 future 객체에서 값을 가져오는 방법이 있습니다.
promise 와 너무 비슷해보이지만 이 pakaged_task 는 사실 쓰레드를 만들면서 꼭 하나의 pakaged_task를 넘겨야하는게 아닌 여러 객체를 넘겨서 
한번에 처리하도록 할 수도 있습니다. 


이 모든 방법 또는 future 객체를 꼭 사용해야하는것은 아니지만 일단 이런 개념이 있다라고 알고 넘어가는겁니다.  
*/

int64 Calculate()
{
	int64 sum = 0;
	
	for (int32 i = 0; i < 100'000; i++)
		sum += i;

	return sum;
}

void PromiseWorker(std::promise<string>&& promise)
{
	promise.set_value("Set Promise Massage");
}

void TaskWorker(std::packaged_task<int64(void)>&& task)
{
	task();
}

int main()
{
	// 동기(Synchronous) 실행
	int64 sum = Calculate();
	cout << sum << endl;

	
	{
		// Future 객체를 생성하는 방법 
		// 인자의 뜻 async(비동기화)로 Calculate 를 실행해달라 
		// 첫번째 인자로 3가지 옵션을 줄 수 있습니다. 
		// 1) async				: 별도의 쓰레드를 만들어 실행하세요 
		// 2) deffered			: lazy evaluation 지연해서 실행하세요 
		// 3) deffered | async	: 둘 중 알아서 골라주세요 
		std::future<int64> future = std::async(std::launch::async, Calculate);

		// TODO : future 객체를 만든 후 당장 그 값이 필요하지 않다면 다른 작업들을 진행합니다. 

		// 한참 후에 future 값이 필요해진다면 
		int64 sum = future.get(); 
		// async 로 만들었다면 별도의 쓰레드에서 계산해둔 값을 가져오는것 
		// deffered 로 만들었다면 사실은 int64 sum = Calculate(); 와 다르지 않습니다. 

		// deffered 는 그냥 함수호출을 지연시키는건데 어떤 의미가 있을까?
		// 커맨트 패턴에서 필요한 경우가 생깁니다.
		// 한번에 일감이 몰려서 일감들을 미뤄둬야할때 지금처럼 지연시켜서 나중에 실행하도록 할 수 있습니다. 

		// 경우에 따라서 future의 진행 상황을 알고 싶을때가 있습니다. 
		// 그럴때 future 객체의 wait_for 를 하게 되면 인자에 준 시간이 흐르고 나서 future_status 를 반환합니다.   
		std::future_status status = future.wait_for(1ms);
		if (status == std::future_status::ready)
		{

		}
		// wait_for 말고 그냥 wait 는 무한정으로 기다린다는 것입니다. 사실상 .get() 과 별 차이가 없습니다. 


		// 추가로 future 객체에 넘겨줄 함수를 그냥 함수가 아니라 클래스에 포함된 멤버함수를 넘겨줄 때도 있을겁니다. 
		{
			class Knight
			{
			public:
				int64 GetHp() { return 100; }
			};

			// 객체의 멤버 함수는 객체에 포함된 데이터 이다 보니 객체가 있고 그걸 같이 넘겨줘야합니다. 
			Knight knight;
			std::future<int64> future2 = std::async(std::launch::async, Knight::GetHp, knight);
		}

	}

	// future 객체가 꼭 async 를 통해만 만들수 있는건 아닙니다. 
	// std::promise
	{
		// 프로미스 객체를 만들고 퓨처객체와 get_future 함수를 통해 둘을 연동 시킬 수 있습니다. 
		std::promise<string> promise;
		std::future<string> future = promise.get_future();

		// 이후 promise에 Set 함수를 통해 갑을 세팅해주면 나중에 future.get()으로 그 값을 가져올 수 있습니다. 
		thread t(PromiseWorker, std::move(promise));

		string msg = future.get();
		cout << msg << endl;
		t.join();
	}

	// std::pakaged_task
	{
		std::packaged_task<int64(void)> task(Calculate);
		std::future<int64> future = task.get_future();

		thread t(TaskWorker, std::move(task));
		
		int64 sum = future.get();
		cout << sum << endl;
		t.join();
	}
}
