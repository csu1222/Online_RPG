#include "pch.h"
#include "DeadLockProfiler.h"

void DeadLockProfiler::PushLock(const char* name)
{
	LockGuard guard(_lock);

	// ���̵� ã�ų� �߱��Ѵ�
	int32 lockId = 0;

	auto findIt = _nameToId.find(name);
	if (findIt == _nameToId.end())	// name���� �˻� ����� ���ٸ� 
	{
		lockId = static_cast<int32>(_nameToId.size());	// _nameToId�� �ִ�ũ�Ⱑ ���̵� 
		_nameToId[name] = lockId;
		_idToName[lockId] = name;
	}
	else // name�� �߰��� �ȴٸ� 
	{
		lockId = findIt->second;
	}

	// ��� �ִ� ���� �־��ٸ� 
	if (_lockStack.empty() == false)
	{
		// ������ �߰ߵ��� ���� ���̽���� ����� ���θ� �ٽ� Ȯ���Ѵ�.
		const int32 prevId = _lockStack.top();
		if (lockId != prevId)	// �̹� �������� ���� ���� �ٸ��ٸ� 
		{
			set<int32>& history = _lockHistory[prevId];	// �������� �����丮�� ������
			if (history.find(lockId) == history.end())	// �������� �����丮�� ������� �̹� �ִ�����üũ
			{
				// ���ٸ� �����丮�� �߰��ϰ� ����Ŭüũ 
				history.insert(lockId);
				CheckCycle();
			}
		}
	}

	// ����ִ¶��� �����ٸ�
	_lockStack.push(lockId);
}

void DeadLockProfiler::PopLock(const char* name)
{
	LockGuard guard(_lock);

	// �������� ����ִٸ� �̻��� ��Ȳ
	if (_lockStack.empty())
		CRASH("MUTIPLE_UNLOCK");

	// ������ ���� �������� ž�� �ƴϾ �̻��� ��Ȳ
	int32 lockId = _nameToId[name];
	if (_lockStack.top() != lockId)
		CRASH("INVALID_UNLOCK");

	// �����ϸ� ��
	_lockStack.pop();
}

void DeadLockProfiler::CheckCycle()
{
	// ȣ��� �������� �߰��� ������ ��
	const int32 lockCount = static_cast<int32>(_nameToId.size());
	// lockCount�� ũ��� Dfs �� ���� �����̳ʵ��� �ʱ�ȭ 
	_discoveredOrder = vector<int32>(lockCount, -1);
	_discoveredCount = 0;
	_finished = vector<bool>(lockCount, false);
	_parent = vector<int32>(lockCount, -1);

	for (int32 lockId = 0; lockId < lockCount; lockId++)
		Dfs(lockId);

	// ������ �������� �����Ѵ� 
	_discoveredOrder.clear();
	_finished.clear();
	_parent.clear();
}

void DeadLockProfiler::Dfs(int32 here)
{
	// �̹� �߰ߵ� ���̶�� �ٷ� ����
	if (_discoveredOrder[here] != -1)
		return;

	// ó�� �湮�ϸ� �湮�ϰ� �ִ� ���� ������ �ű�ϴ�.
	_discoveredOrder[here] = _discoveredCount++;

	// ��� ������ ������ ��ȸ
	// �� ���� �����丮�� �����ɴϴ�.
	auto findIt = _lockHistory.find(here);
	// ���� �� ���� �����丮�� ���ٸ� 
	if (findIt == _lockHistory.end())	
	{
		// �������� ���� ���� ���¿��� �ٸ� ���� �������� ���°� 
		_finished[here] = true;
		return;
	}
	
	// ��ø���� ���� ���� �ִٸ� ����Ŭ �Ǻ� 
	set<int32>& nextSet = findIt->second;
	for (int32 there : nextSet)
	{
		// ���� �湮������ ���ٸ� �湮�Ѵ�
		if (_discoveredOrder[there] == -1)
		{
			_parent[there] = here;
			Dfs(there);
			continue;
		}
		// �湮�� ���� �ִٸ� ����Ŭ �Ǻ� 

		// here�� there���� ���� �߰� �Ǿ��ٸ� there�� here�� �ļ��̴�. (������ ����)
		if (_discoveredOrder[here] < _discoveredOrder[there])
			continue;

		// �������� �ƴϰ�. Dfs(there) �� ���� �������� �ʾҴٸ�, there�� here�� �����̴�. (������ ����)
		if (_finished[there] == false)
		{
			printf("%s -> %s\n", _idToName[here], _idToName[there]);

			int32 now = here;
			while (true)
			{

				printf("%s -> %s\n", _idToName[_parent[now]], _idToName[now]);
				now = _parent[now];
				if (now == there)
					break;
			}
			CRASH("DEADLOCK_DETECTED");
		}
	}

	_finished[here] = true;
}
