#pragma once

#include <mutex>

template<typename T>
class LockStack
{
public:
	LockStack() { }

	// LockStack 복사를 막아줍니다. 
	LockStack(const LockStack&) = delete;
	LockStack& operator=(const LockStack&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> guard(_mutex);
		_stack.push(std::move(value));

		_condVar.notify_one();	// 조건변수에게 Push 했음을 알림
	}

	// 반환 값으로 Pop 성공여부를 반환하고 Pop 한 데이터는 인자에 담아 내보낼것
	bool TryPop(T& value)
	{
		lock_guard<mutex> guard(_mutex);
		if (_stack.empty())
			return false;

		value = std::move(_stack.top());
		_stack.pop();

		return true;
	}

	// 보통은 empty 를 체크해서 pop 을 하던지 하는데 멀티쓰레드 환경에서는 사실
	// 큰 의미가 없습니다. 
	// Empty() 체크 후 Pop() 으로 진행되는 사이에 다른 쓰레드에서 먼저 Pop()을 할 수도 있기 때문 
	//bool Empty()
	//{
	//	lock_guard<mutex> guard(_mutex);
	//	return _stack.empty();
	//}

	// 컨테이너를 사용할때 계속 루프를 돌면서 체크하는 방법 대신 조건 변수를 활용 할 수 있을겁니다. 
	void WaitPop(T& value)
	{
		unique_lock<mutex> _lock(_mutex);
		_condVar.wait(lock, [this]() { return _stack.empty() == false; });
		value = std::move(_stack.top());
		_stack.pop();
	}

private:
	// 굳이 전부 새로 만들 필요없이 표준 스택을 가져와 사용
	stack<T>	_stack;
	mutex		_mutex;

	// 조건변수 추가
	condition_variable _condVar;
};

