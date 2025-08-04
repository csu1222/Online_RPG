// Copyright Epic Games, Inc. All Rights Reserved.

#include "LC_5_5.h"
#include "LcLogChannels.h"
#include "Modules/ModuleManager.h"

class FLCGameModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

void FLCGameModule::StartupModule()
{
	FDefaultGameModuleImpl::StartupModule();

	UE_LOG(LogLC, Warning, TEXT("LC module has started!"));
}

void FLCGameModule::ShutdownModule()
{
	FDefaultGameModuleImpl::ShutdownModule();
}


IMPLEMENT_PRIMARY_GAME_MODULE(FLCGameModule, LC_5_5, "LC_5_5");
