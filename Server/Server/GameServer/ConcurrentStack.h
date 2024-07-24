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
	// ���� ����ī��Ʈ�� ī�����ϴ� ��� 
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
		// �Ʒ� ������ �ڵ�� ���ø޸𸮿����� �����ϱ� ������ ������ �������մϴ�.
		CountedNodePtr node;
		node.ptr = new Node(value);
		node.externalCount = 1;

		// ������� �������� ������ �� �ִ� ��带 ����ϱ� ������ ������ ������ ���� �ʽ��ϴ�.
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
			// ������ ȹ�� (externalCount�� ������ ���� +1 �� �ְ� ����)
			IncreaseHeadCount(oldHead);
			// �ּ��� oldHead�� externalCount >= 2 ���״� ����X (�����ϰ� ���ٰ���)
			Node* ptr = oldHead.ptr;

			// ������ ���� üũ 
			if (ptr == nullptr)
				return shared_ptr<T>();
			
			// ������ ȹ�� (ptr->next�� _head�� �ٲ�ġ���� �����尡 ����)
			if (_head.compare_exchange_strong(oldHead, ptr->next))
			{
				// ������ȹ��
				// �¸��ߴٸ� ptr �Ӹ��ƴ϶� externalCount ���� �����ؾ��Ѵ�
				shared_ptr<T> res;
				res.swap(ptr->data);
				
				// �������� ���� �����͸� ������ ������ �����ص� �Ǵ����� ����
				const int32 countIncrease = oldHead.externalCount - 2;
				if (ptr->internalCount.fetch_add(countIncrease) == -countIncrease)
					delete ptr;

				return res;
			}
			else if (ptr->internalCount.fetch_add(-1) == 1)
			{
				// �������� ������� �������� ���� -> �޼����� �����Ѵ� 
				delete ptr;
			}
		}
	}

private:
	// oldHead ������ ����ī��Ʈ�� �������Ѿ��ϴµ� ��Ƽ������ ������ ���� �� ������ CAS �� �մϴ�.
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
	// ��������Ϳ� ���� ī��Ʈ�� ������ϰ� �����ϰڴ� 
	atomic<CountedNodePtr> _head;
};