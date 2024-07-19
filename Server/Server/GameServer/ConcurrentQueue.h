#pragma once
#include <mutex>

// LockQueue 도 LockStack과 대칭적입니다. 
template<typename T>
class LockQueue
{
public:
	LockQueue() { }

	LockQueue(LockQueue&) = delete;
	LockQueue& operator=(LockQueue&) = delete;

	void Push(T value)
	{
		lock_guard<mutex> _lock(_mutex);
		_queue.push(std::move(value)); 
		_condVar.notify_one();
	}

	bool TryPop(T& value)
	{
		lock_guard<mutex> guard(_mutex);
		if (_queue.empty())
			return false;

		value = std::move(_queue.front());
		_queue.pop();

		return true;
	}

	void WaitPop(T& value)
	{
		unique_lock<mutex> _lock(_mutex);
		_condVar.wait(lock, [this]() { return _queue.empty() == false; });
		value = std::move(_queue.front());
		_queue.pop();
	}

private:
	queue<T> _queue;
	mutex _mutex;

	condition_variable _condVar;
};

