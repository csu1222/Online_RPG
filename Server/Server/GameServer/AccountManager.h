#pragma once
#include <mutex>

class Account
{
	// TODO
};

class AccountManager
{
public:
	static AccountManager* Instance()
	{
		static AccountManager accountManager;

		return &accountManager;
	}

	Account* GetAccount(int32 id)
	{
		lock_guard<mutex> _guard(_mutex);

		return nullptr;
	}

	void ProcessLogin();

private:
	mutex _mutex;
};

