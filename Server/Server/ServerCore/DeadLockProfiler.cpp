#include "pch.h"
#include "DeadLockProfiler.h"

void DeadLockProfiler::PushLock(const char* name)
{
	LockGuard guard(_lock);

	// 아이디를 찾거나 발급한다
	int32 lockId = 0;

	auto findIt = _nameToId.find(name);
	if (findIt == _nameToId.end())	// name으로 검색 결과가 없다면 
	{
		lockId = static_cast<int32>(_nameToId.size());	// _nameToId의 최대크기가 아이디 
		_nameToId[name] = lockId;
		_idToName[lockId] = name;
	}
	else // name이 발견이 된다면 
	{
		lockId = findIt->second;
	}

	// 잡고 있는 락이 있었다면 
	if (_lockStack.empty() == false)
	{
		// 기존에 발견되지 않은 케이스라면 데드라 여부를 다시 확인한다.
		const int32 prevId = _lockStack.top();
		if (lockId != prevId)	// 이미 잡힌락과 지금 락이 다르다면 
		{
			set<int32>& history = _lockHistory[prevId];	// 이전락의 히스토리를 가져와
			if (history.find(lockId) == history.end())	// 이전락의 히스토리에 현재락이 이미 있는지를체크
			{
				// 없다면 히스토리에 추가하고 사이클체크 
				history.insert(lockId);
				CheckCycle();
			}
		}
	}

	// 잡고있는락이 없었다면
	_lockStack.push(lockId);
}

void DeadLockProfiler::PopLock(const char* name)
{
	LockGuard guard(_lock);

	// 락스택이 비어있다면 이상한 상황
	if (_lockStack.empty())
		CRASH("MUTIPLE_UNLOCK");

	// 해제할 락이 락스택의 탑이 아니어도 이상한 상황
	int32 lockId = _nameToId[name];
	if (_lockStack.top() != lockId)
		CRASH("INVALID_UNLOCK");

	// 안전하면 팝
	_lockStack.pop();
}

void DeadLockProfiler::CheckCycle()
{
	// 호출될 시점까지 추가된 락들의 수
	const int32 lockCount = static_cast<int32>(_nameToId.size());
	// lockCount의 크기로 Dfs 에 사용될 컨테이너들을 초기화 
	_discoveredOrder = vector<int32>(lockCount, -1);
	_discoveredCount = 0;
	_finished = vector<bool>(lockCount, false);
	_parent = vector<int32>(lockCount, -1);

	for (int32 lockId = 0; lockId < lockCount; lockId++)
		Dfs(lockId);

	// 연산이 끝났으면 정리한다 
	_discoveredOrder.clear();
	_finished.clear();
	_parent.clear();
}

void DeadLockProfiler::Dfs(int32 here)
{
	// 이미 발견된 락이라면 바로 리턴
	if (_discoveredOrder[here] != -1)
		return;

	// 처음 방문하면 방문하고 있는 락의 순번을 매깁니다.
	_discoveredOrder[here] = _discoveredCount++;

	// 모든 인접한 정점을 순회
	// 이 락의 히스토리를 가져옵니다.
	auto findIt = _lockHistory.find(here);
	// 만약 이 락의 히스토리가 없다면 
	if (findIt == _lockHistory.end())	
	{
		// 아직까지 락을 잡은 상태에서 다른 락을 잡은적이 없는것 
		_finished[here] = true;
		return;
	}
	
	// 중첩락을 잡은 적이 있다면 사이클 판별 
	set<int32>& nextSet = findIt->second;
	for (int32 there : nextSet)
	{
		// 아직 방문한적이 없다면 방문한다
		if (_discoveredOrder[there] == -1)
		{
			_parent[there] = here;
			Dfs(there);
			continue;
		}
		// 방문한 적이 있다면 사이클 판별 

		// here가 there보다 먼저 발견 되었다면 there는 here의 후손이다. (순방향 간선)
		if (_discoveredOrder[here] < _discoveredOrder[there])
			continue;

		// 순방향이 아니고. Dfs(there) 가 아직 종료하지 않았다면, there는 here의 선조이다. (역방향 간선)
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
