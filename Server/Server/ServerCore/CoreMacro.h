#pragma once

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