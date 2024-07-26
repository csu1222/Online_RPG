#pragma once
#include <stack>
#include <map>
#include <vector>

// WriteLock, WriteUnlock 을 할때 이 클래스를 끼워 넣어서 사이클이 일어나는지를 체크할것입니다. 
class DeadLockProfiler
{
public:
	void PushLock(const char* name);
	void PopLock(const char* name);
	void CheckCycle();

private:
	void Dfs(int32 index);

private:
	unordered_map<const char*, int32>	_nameToId;
	unordered_map<int32, const char*>	_idToName;
	map<int32, set<int32>>				_lockHistory;

	Mutex _lock;

private:
	vector<int32> _discoveredOrder; // 노드가 발견된 순서를 기록하는 배역
	int32 _discoveredCount = 0; // 노드가 발견된 순서 
	vector<bool> _finished;	// Dfs(i) 가 종료되었는지 여부
	vector<int32> _parent;
};

