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
	struct Node
	{
		Node(const T& value) : data(value), next(nullptr)
		{

		}

		T data;
		Node* next;
	};

public:

	void Push(const T& value)
	{
		// 1) 새 노드를 만들고 
		// 2) 새 노드의 next = head
		// 3) head = 새 노드

		Node* node = new Node(value);
		node->next = _head;

		// 멀티쓰레드 상황에서는 이 사이에 문제가 생깁니다. 
		//_head = node;

		while (_head.compare_exchange_weak(node->next, node) == false)
		{

		}
		/*
		// 위의 코드를 풀어 보자면 
		if (_head == node->next)
		{
			_head = node;
			return true;
		}
		{
			node->next = _head;
			return false;
		}
		// 그래서 node->next 가 _head 인지 체크하는것과 _head 가 node 를 가리키게 하는동작을 원자적으로 수행
		*/
	}

	bool TryPop(T& value)
	{
		// 스택을 이루는 노드들 중 가장 앞 노드를 꺼내는것이 목적
		// 1) head 읽기
		// 2) head->next 읽기
		// 3) head = head->next
		// 4) data 추출해서 반환 
		// 5) 추출한 노드 삭제

		++_popCount;	// _popCount 증가 
		
		Node* oldHead = _head;

		while (oldHead && _head.compare_exchange_weak(oldHead, oldHead->next) == false)
		{

		}
		/*
		if (_head == oldHead)
		{
			_head = oldHead->next;
			return true;
		}
		{
			oldHead = _head;
			return false;
		}
		*/

		if (oldHead == nullptr)
		{
			--_popCount;	// Pop 할 노드가 없으므로 popCount 감소 
			return false;
		}

		// Exception X
		value = oldHead->data; 

		// 여기 까지 왔으면 oldHead를 삭제할 수 있는지는 모르지만 삭제 시도를 합니다.
		TryDelete(oldHead);

		//delete oldHead;
		// 그런데 여기서 oleHead 를 삭제할때 다른 쓰레드에서 이 노드를 Pop 하려고 들어 왔다면 
		// 삭제한 oldHead 주소에 접근해 compare_exchange_weak 를 시도하게 됩니다. 

		// C#이나 Java 같은 garbage collector 가 있었다면 따로 신경쓸 일도 없을 겁니다. 

		

		return true;
	}

	void TryDelete(Node* oldHead)
	{
		// 나 외에 누가 있는지?
		if (_popCount == 1)
		{
			// _popCount가 1이라면 현재 TryPop 을 하는 쓰레드가 자신뿐
			
			// 이와 혼자인거, 삭제 예약된 다른 데이터들도 삭제
			Node* node = _pendingList.exchange(nullptr);

			// 다시 _popCount 체크
			if (_popCount.fetch_add(-1) == 0)
			{
				// 끼어든 쓰레드가 없슴 -> 삭제 진행 
				// 위에서 이미 기존 _pendingList의 노드는 분리한 후
				DeleteNode(node);
			}
			else if(node)
			{
				// 누가 끼어들었으니 다시 _pendingList에 다시 갖다 놓기 
				ChainPendingNodeList(node);
			}

			// 내 데이터는 삭제
			delete oldHead;
		}
		else
		{
			// 아직 나 말고 다른 쓰레드가 있다 
			// 삭제 예약만 합니다.
			ChainPendingNode(oldHead); 
			_popCount.fetch_add(-1);
		}
		
		// 멀티쓰레드 환경이니깐 TryDelete에 들어와도 다른 쓰레드가 oldHead에 접근 할 수 있지 않은가?
		// 하지만 지금 코드를 만든 구조는
		// 1) 데이터 분리
		// 2) Count 체크
		// 3) 나 혼자면 삭제 
		// 의 순서를 가지고 있습니다. TryPop에서 _head.compare_exchange_weak 를 호출한 순간 
		// oldHead는 기존 스택에서 떨어져 분리되어 그 순간 같이 접근한 쓰레드들만 알 수 있습니다. 
	}
	
	
	void ChainPendingNodeList(Node* first, Node* last)
	{
		// _pendingList 앞에 이어줍니다. 
		last->next = _pendingList;

		// 누가 끼어들었는지 체크하면서 _pendingList를 first로 교체
		while (_pendingList.compare_exchange_weak(last->next, first))
		{
			// 중간에 누가 끼어들어서 _pendingList 와 last->next 가 일치 하지 않으면 계속 시도
		}
	}

	// ChainPendingNodeList 를 노드 하나만 받았을경우 헬퍼 함수 
	void ChainPendingNodeList(Node* node)
	{
		Node* last = node;

		// last->next 가 nullptr 일때 까지 이동
		while (last->next)
		{
			last = last->next;
		}

		// first 와 last 가 구해졌으니 ChainPendingNodeList 호출
		ChainPendingNodeList(node, last);
	}

	// _pendingList 에 노드 딱 하나만 연결해주는 함수
	void ChainPendingNode(Node* node)
	{
		ChainPendingNodeList(node, node);
	}

	static void DeleteNode(Node* node)
	{
		// 연결된 노드들을 순차적으로 삭제해야한다 
		while (node)
		{
			Node* next = node->next;
			delete node;
			node = next;
		}
	}

private:
	// 실제 데이터들중 가장 앞에 있는 데이터를 가리킬 헤더
	atomic<Node*> _head;

	atomic<uint32> _popCount = 0; // Pop을 실행중인 쓰레드 갯수
	atomic<Node*> _pendingList;	  // 삭제 되어야 할 노드들(첫번째 노드)
};