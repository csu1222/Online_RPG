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

template<typename T>
class LockFreeStack
{
	// 직접 참조카운트를 카운팅하는 방식 
	struct Node;
	struct CountedNodePtr
	{
		int32 externalCount = 0;
		Node* ptr = nullptr;
	};

	struct Node
	{
		Node(const T& value) : data(make_shared<T>(value))
		{

		}

		shared_ptr<T> data;
		atomic<int32> internalCount = 0;
		CountedNodePtr next;
	};

public:

	void Push(const T& value)
	{
		// 아래 세줄의 코드는 스택메모리에서만 동작하기 때문에 쓰레드 세이프합니다.
		CountedNodePtr node;
		node.ptr = new Node(value);
		node.externalCount = 1;

		// 여기부터 공동으로 접근할 수 있는 헤드를 사용하기 때문에 쓰레드 세이프 하지 않습니다.
		node.ptr->next = _head;
		while (_head.compare_exchange_weak(node.ptr->next, node) == false)
		{
			
		}
	}

	shared_ptr<T> TryPop()
	{
		CountedNodePtr oldHead = _head;
		while (true)
		{
			// 참조권 획득 (externalCount를 현시점 기준 +1 한 애가 승자)
			IncreaseHeadCount(oldHead);
			// 최소한 oldHead의 externalCount >= 2 일테니 삭제X (안전하게 접근가능)
			Node* ptr = oldHead.ptr;

			// 데이터 유무 체크 
			if (ptr == nullptr)
				return shared_ptr<T>();
			
			// 소유권 획득 (ptr->next로 _head를 바꿔치기한 쓰레드가 승자)
			if (_head.compare_exchange_strong(oldHead, ptr->next))
			{
				// 소유권획득
				// 승리했다면 ptr 뿐만아니라 externalCount 까지 동일해야한다
				shared_ptr<T> res;
				res.swap(ptr->data);
				
				// 소유권을 가져 데이터를 꺼내도 되지만 삭제해도 되는지는 별개
				const int32 countIncrease = oldHead.externalCount - 2;
				if (ptr->internalCount.fetch_add(countIncrease) == -countIncrease)
					delete ptr;

				return res;
			}
			else if (ptr->internalCount.fetch_add(-1) == 1)
			{
				// 참조권은 얻었으나 소유권은 실패 -> 뒷수습은 내가한다 
				delete ptr;
			}
		}
	}

private:
	// oldHead 생성과 참조카운트를 증가시켜야하는데 멀티쓰레드 경합이 있을 수 있으니 CAS 를 합니다.
	void IncreaseHeadCount(CountedNodePtr& oldCounter)
	{
		while (true)
		{
			CountedNodePtr newCounter = oldCounter;
			newCounter.externalCount++;

			if (_head.compare_exchange_strong(oldCounter, newCounter))
			{
				oldCounter.externalCount = newCounter.externalCount;
				break;
			}
		}
	}

private:
	// 노드포인터와 참조 카운트를 아토믹하게 관리하겠다 
	atomic<CountedNodePtr> _head;
};