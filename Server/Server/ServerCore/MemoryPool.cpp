#include "pch.h"
#include "MemoryPool.h"

/*-----------------
	MemoryPool
------------------*/

MemoryPool::MemoryPool(int32 allocSize) : _allocSize(allocSize)
{
	::InitializeSListHead(&_header);
}

MemoryPool::~MemoryPool()
{
	// 소멸할때 Pop을 해서 그 값이 nullptr 이 아닐때 까지 반복 
	while (MemoryHeader* memory = static_cast<MemoryHeader*>(::InterlockedPopEntrySList(&_header)))
	{
		// 아직 값이 있다면 16바이트 정렬하면서 삭제
		::_aligned_free(memory);
	}
}

void MemoryPool::Push(MemoryHeader* ptr)
{
	ptr->allocSize = 0;

	::InterlockedPushEntrySList(&_header, static_cast<PSLIST_ENTRY>(ptr));

	_useCount.fetch_sub(1);
	_reserveCount.fetch_add(1);
}

MemoryHeader* MemoryPool::Pop()
{
	// 곧바로 Pop 을 합니다. 
	MemoryHeader* memory = static_cast<MemoryHeader*>(::InterlockedPopEntrySList(&_header));

	// 없으면 새로 만들다
	if (memory == nullptr)
	{
		// 기존 malloc 은 16바이트 정렬이 된다는 보장이 없기때문에 _aligned_malloc 사용
		memory = reinterpret_cast<MemoryHeader*>(::_aligned_malloc(_allocSize, SLIST_ALIGNMENT));
	}
	else
	{
		ASSERT_CRASH(memory->allocSize == 0);
		_reserveCount.fetch_sub(1);
	}

	_useCount.fetch_add(1);

	return memory;
}
