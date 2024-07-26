#include "pch.h"
#include "Lock.h"
#include "CoreTLS.h"
#include "DeadLockProfiler.h"

void Lock::WriteLock(const char* name)
{
	// 디버그 모드일때만 사이클 체크
#if _DEBUG
	GDeadLockProfiler->PushLock(name);
#endif

	// 동일한 쓰레드가 소유하고 있다면 무조건 성공
	const uint32 lockThreadId = (_lockFlag.load() & WRITE_THREAD_MASK) >> 16;
	if (LThreadId == lockThreadId)
	{
		_writeCount++;
		return;
	}

	// 데드락 상황이거나 너무 오래걸리면 의도적으로 크래시를 내겠습니다.
	const int64 beginTick = ::GetTickCount64(); // 시작시간

	const uint32 desired = ((LThreadId << 16) & WRITE_THREAD_MASK);

	while (true)
	{
		for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
		{
			uint32 expected = EMPTY_FLAG;
			if (_lockFlag.compare_exchange_strong(OUT expected, desired))
			{
				_writeCount++;
				return;
			}
		}

		// 경과한 시간이 너무 길면 크래시
		if (::GetTickCount64() - beginTick >= ACQUIRE_TIMEOUT)
			CRASH("LOCK_TIME_OUT");

		this_thread::yield();
	}
}

void Lock::WriteUnlock(const char* name)
{
	// 디버그 모드일때만 사이클 체크
#if _DEBUG
	GDeadLockProfiler->PopLock(name);
#endif

	// ReadLock 다 풀기 전에 WriteUnlock 불가능
	if ((_lockFlag.load() & READ_COUNT_MASK) != 0)
		CRASH("INVALID_UNLOCK_ORDER");

	const int32 lockCount = --_writeCount;
	if (lockCount == 0)
		_lockFlag.store(EMPTY_FLAG);
}

void Lock::ReadLock(const char* name)
{
	// 디버그 모드일때만 사이클 체크
#if _DEBUG
	GDeadLockProfiler->PushLock(name);
#endif

	// 동일한 쓰레드가 소유하고 있다면 무조건 성공
	const uint32 lockThreadId = (_lockFlag.load() & WRITE_THREAD_MASK) >> 16;
	if (LThreadId == lockThreadId)
	{
		_lockFlag.fetch_add(1);
		return;
	}

	// 아무도 소유하고 있지 않을 때 경합해서 공유 카운트를 올린다.
	const int64 beginTick = ::GetTickCount64();
	while (true)
	{
		for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
		{
			// Write 락 플레그 부분을 0으로 밀고 비교를 할것이니 Write락이 잡히지 않은 상황을 말함
			uint32 expected = (_lockFlag.load() & READ_COUNT_MASK);

			// 성공했다면 락을 잡았다는것 실패했다면 write락이 먼저 잡혀있거나 중간에 새치기를 당해 expected 값이 달라졌거나
			if (_lockFlag.compare_exchange_strong(OUT expected, expected + 1))
				return;
		}

		if (::GetTickCount64() - beginTick >= ACQUIRE_TIMEOUT)
			CRASH("LOCK_TIME_OUT");

		this_thread::yield();
	}
}

void Lock::ReadUnlock(const char* name)
{
	// 디버그 모드일때만 사이클 체크
#if _DEBUG
	GDeadLockProfiler->PopLock(name);
#endif

	if ((_lockFlag.fetch_sub(1) & READ_COUNT_MASK) == 0)
	{
		// 여기로 들어왔다면 ReadUnlock 하기 전부터 Read Count 가 0이었다
		CRASH("MULTIPLE_UNLOCK");
	}
}
