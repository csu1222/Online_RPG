#pragma once

#include <mutex>

template<typename T>
class LockStack
{
public:
	LockStack() { }

	// LockStack ���縦 �����ݴϴ�. 
	LockStack(const LockStack&) = delete;
	LockStack& operator=(const LockStack&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> guard(_mutex);
		_stack.push(std::move(value));

		_condVar.notify_one();	// ���Ǻ������� Push ������ �˸�
	}

	// ��ȯ ������ Pop �������θ� ��ȯ�ϰ� Pop �� �����ʹ� ���ڿ� ��� ��������
	bool TryPop(T& value)
	{
		lock_guard<mutex> guard(_mutex);
		if (_stack.empty())
			return false;

		value = std::move(_stack.top());
		_stack.pop();

		return true;
	}

	// ������ empty �� üũ�ؼ� pop �� �ϴ��� �ϴµ� ��Ƽ������ ȯ�濡���� ���
	// ū �ǹ̰� �����ϴ�. 
	// Empty() üũ �� Pop() ���� ����Ǵ� ���̿� �ٸ� �����忡�� ���� Pop()�� �� ���� �ֱ� ���� 
	//bool Empty()
	//{
	//	lock_guard<mutex> guard(_mutex);
	//	return _stack.empty();
	//}

	// �����̳ʸ� ����Ҷ� ��� ������ ���鼭 üũ�ϴ� ��� ��� ���� ������ Ȱ�� �� �� �����̴ϴ�. 
	void WaitPop(T& value)
	{
		unique_lock<mutex> _lock(_mutex);
		_condVar.wait(lock, [this]() { return _stack.empty() == false; });
		value = std::move(_stack.top());
		_stack.pop();
	}

private:
	// ���� ���� ���� ���� �ʿ���� ǥ�� ������ ������ ���
	stack<T>	_stack;
	mutex		_mutex;

	// ���Ǻ��� �߰�
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
		// 1) �� ��带 ����� 
		// 2) �� ����� next = head
		// 3) head = �� ���

		Node* node = new Node(value);
		node->next = _head;

		// ��Ƽ������ ��Ȳ������ �� ���̿� ������ ����ϴ�. 
		//_head = node;

		while (_head.compare_exchange_weak(node->next, node) == false)
		{

		}
		/*
		// ���� �ڵ带 Ǯ�� ���ڸ� 
		if (_head == node->next)
		{
			_head = node;
			return true;
		}
		{
			node->next = _head;
			return false;
		}
		// �׷��� node->next �� _head ���� üũ�ϴ°Ͱ� _head �� node �� ����Ű�� �ϴµ����� ���������� ����
		*/
	}

	bool TryPop(T& value)
	{
		// ������ �̷�� ���� �� ���� �� ��带 �����°��� ����
		// 1) head �б�
		// 2) head->next �б�
		// 3) head = head->next
		// 4) data �����ؼ� ��ȯ 
		// 5) ������ ��� ����

		++_popCount;	// _popCount ���� 
		
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
			--_popCount;	// Pop �� ��尡 �����Ƿ� popCount ���� 
			return false;
		}

		// Exception X
		value = oldHead->data; 

		// ���� ���� ������ oldHead�� ������ �� �ִ����� ������ ���� �õ��� �մϴ�.
		TryDelete(oldHead);

		//delete oldHead;
		// �׷��� ���⼭ oleHead �� �����Ҷ� �ٸ� �����忡�� �� ��带 Pop �Ϸ��� ��� �Դٸ� 
		// ������ oldHead �ּҿ� ������ compare_exchange_weak �� �õ��ϰ� �˴ϴ�. 

		// C#�̳� Java ���� garbage collector �� �־��ٸ� ���� �Ű澵 �ϵ� ���� �̴ϴ�. 

		

		return true;
	}

	void TryDelete(Node* oldHead)
	{
		// �� �ܿ� ���� �ִ���?
		if (_popCount == 1)
		{
			// _popCount�� 1�̶�� ���� TryPop �� �ϴ� �����尡 �ڽŻ�
			
			// �̿� ȥ���ΰ�, ���� ����� �ٸ� �����͵鵵 ����
			Node* node = _pendingList.exchange(nullptr);

			// �ٽ� _popCount üũ
			if (_popCount.fetch_add(-1) == 0)
			{
				// ����� �����尡 ���� -> ���� ���� 
				// ������ �̹� ���� _pendingList�� ���� �и��� ��
				DeleteNode(node);
			}
			else if(node)
			{
				// ���� ���������� �ٽ� _pendingList�� �ٽ� ���� ���� 
				ChainPendingNodeList(node);
			}

			// �� �����ʹ� ����
			delete oldHead;
		}
		else
		{
			// ���� �� ���� �ٸ� �����尡 �ִ� 
			// ���� ���ุ �մϴ�.
			ChainPendingNode(oldHead); 
			_popCount.fetch_add(-1);
		}
		
		// ��Ƽ������ ȯ���̴ϱ� TryDelete�� ���͵� �ٸ� �����尡 oldHead�� ���� �� �� ���� ������?
		// ������ ���� �ڵ带 ���� ������
		// 1) ������ �и�
		// 2) Count üũ
		// 3) �� ȥ�ڸ� ���� 
		// �� ������ ������ �ֽ��ϴ�. TryPop���� _head.compare_exchange_weak �� ȣ���� ���� 
		// oldHead�� ���� ���ÿ��� ������ �и��Ǿ� �� ���� ���� ������ ������鸸 �� �� �ֽ��ϴ�. 
	}
	
	
	void ChainPendingNodeList(Node* first, Node* last)
	{
		// _pendingList �տ� �̾��ݴϴ�. 
		last->next = _pendingList;

		// ���� ���������� üũ�ϸ鼭 _pendingList�� first�� ��ü
		while (_pendingList.compare_exchange_weak(last->next, first))
		{
			// �߰��� ���� ����� _pendingList �� last->next �� ��ġ ���� ������ ��� �õ�
		}
	}

	// ChainPendingNodeList �� ��� �ϳ��� �޾������ ���� �Լ� 
	void ChainPendingNodeList(Node* node)
	{
		Node* last = node;

		// last->next �� nullptr �϶� ���� �̵�
		while (last->next)
		{
			last = last->next;
		}

		// first �� last �� ���������� ChainPendingNodeList ȣ��
		ChainPendingNodeList(node, last);
	}

	// _pendingList �� ��� �� �ϳ��� �������ִ� �Լ�
	void ChainPendingNode(Node* node)
	{
		ChainPendingNodeList(node, node);
	}

	static void DeleteNode(Node* node)
	{
		// ����� ������ ���������� �����ؾ��Ѵ� 
		while (node)
		{
			Node* next = node->next;
			delete node;
			node = next;
		}
	}

private:
	// ���� �����͵��� ���� �տ� �ִ� �����͸� ����ų ���
	atomic<Node*> _head;

	atomic<uint32> _popCount = 0; // Pop�� �������� ������ ����
	atomic<Node*> _pendingList;	  // ���� �Ǿ�� �� ����(ù��° ���)
};