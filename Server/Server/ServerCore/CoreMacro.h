#pragma once

#define OUT

/*
		Lock
*/
#define USE_MANY_LOCKS(count)	Lock _locks[count];
#define USE_LOCK				USE_MANY_LOCKS(1)
#define READ_LOCK_IDX(idx)		ReadLockGuard readLockGuard_##idx(_locks[idx], typeid(this).name());
#define READ_LOCK				READ_LOCK_IDX(0)
#define WRITE_LOCK_IDX(idx)		WriteLockGuard writeLockGuard_##idx(_locks[idx], typeid(this).name());
#define WRITE_LOCK				WRITE_LOCK_IDX(0)

/*
		Crash 임의로 크래시를 내고싶을때 
*/

#define CRASH(cause)										\
{															\
	uint32* crash = nullptr;								\
	__analysis_assume(crash != nullptr);					\
	*crash = 0xDEADBEEF;									\
}															

/*
		ASSERT_CRASH 인자의 조건이 거짓이라면 크래시를 냅니다.
*/
#define ASSERT_CRASH(expr)									\
{															\
	if (!(expr))											\
	{														\
		CRASH("ASSERT_CRASH");								\
		__analysis_assume(expr);							\
	}														\
}															