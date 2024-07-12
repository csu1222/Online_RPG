#include "pch.h"
#include "UserManager.h"
#include "AccountManager.h"

void UserManager::ProcessSave()
{
	lock_guard<mutex> _guard(_mutex);

	Account* account = AccountManager::Instance()->GetAccount(100);

	// TODO
}
