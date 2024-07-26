#include "pch.h"
#include "Lock.h"
#include "CoreTLS.h"
#include "DeadLockProfiler.h"

void Lock::WriteLock(const char* name)
{
	// ����� ����϶��� ����Ŭ üũ
#if _DEBUG
	GDeadLockProfiler->PushLock(name);
#endif

	// ������ �����尡 �����ϰ� �ִٸ� ������ ����
	const uint32 lockThreadId = (_lockFlag.load() & WRITE_THREAD_MASK) >> 16;
	if (LThreadId == lockThreadId)
	{
		_writeCount++;
		return;
	}

	// ����� ��Ȳ�̰ų� �ʹ� �����ɸ��� �ǵ������� ũ���ø� ���ڽ��ϴ�.
	const int64 beginTick = ::GetTickCount64(); // ���۽ð�

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

		// ����� �ð��� �ʹ� ��� ũ����
		if (::GetTickCount64() - beginTick >= ACQUIRE_TIMEOUT)
			CRASH("LOCK_TIME_OUT");

		this_thread::yield();
	}
}

void Lock::WriteUnlock(const char* name)
{
	// ����� ����϶��� ����Ŭ üũ
#if _DEBUG
	GDeadLockProfiler->PopLock(name);
#endif

	// ReadLock �� Ǯ�� ���� WriteUnlock �Ұ���
	if ((_lockFlag.load() & READ_COUNT_MASK) != 0)
		CRASH("INVALID_UNLOCK_ORDER");

	const int32 lockCount = --_writeCount;
	if (lockCount == 0)
		_lockFlag.store(EMPTY_FLAG);
}

void Lock::ReadLock(const char* name)
{
	// ����� ����϶��� ����Ŭ üũ
#if _DEBUG
	GDeadLockProfiler->PushLock(name);
#endif

	// ������ �����尡 �����ϰ� �ִٸ� ������ ����
	const uint32 lockThreadId = (_lockFlag.load() & WRITE_THREAD_MASK) >> 16;
	if (LThreadId == lockThreadId)
	{
		_lockFlag.fetch_add(1);
		return;
	}

	// �ƹ��� �����ϰ� ���� ���� �� �����ؼ� ���� ī��Ʈ�� �ø���.
	const int64 beginTick = ::GetTickCount64();
	while (true)
	{
		for (uint32 spinCount = 0; spinCount < MAX_SPIN_COUNT; spinCount++)
		{
			// Write �� �÷��� �κ��� 0���� �а� �񱳸� �Ұ��̴� Write���� ������ ���� ��Ȳ�� ����
			uint32 expected = (_lockFlag.load() & READ_COUNT_MASK);

			// �����ߴٸ� ���� ��Ҵٴ°� �����ߴٸ� write���� ���� �����ְų� �߰��� ��ġ�⸦ ���� expected ���� �޶����ų�
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
	// ����� ����϶��� ����Ŭ üũ
#if _DEBUG
	GDeadLockProfiler->PopLock(name);
#endif

	if ((_lockFlag.fetch_sub(1) & READ_COUNT_MASK) == 0)
	{
		// ����� ���Դٸ� ReadUnlock �ϱ� ������ Read Count �� 0�̾���
		CRASH("MULTIPLE_UNLOCK");
	}
}
