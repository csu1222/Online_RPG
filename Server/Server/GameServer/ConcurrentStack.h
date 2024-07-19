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

