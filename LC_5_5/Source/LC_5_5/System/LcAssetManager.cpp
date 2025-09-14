// Fill out your copyright notice in the Description page of Project Settings.

#include "System/LcAssetManager.h"
#include "LcLogChannels.h"
#include "LcGameplayTags.h"

ULcAssetManager::ULcAssetManager()
{
}

ULcAssetManager& ULcAssetManager::Get()
{
	check(GEngine);

	// �츮�� AssetManager�� GEngine�� AssetManager�� Ŭ������ �������̵� �߱� ������, GEngine�� AssetManager�� ����
	if (ULcAssetManager* singleton = Cast<ULcAssetManager>(GEngine->AssetManager))
	{
		return *singleton;
	}

	UE_LOG(LogLC, Fatal, TEXT("invalid AssetManagerClassname in DefaultEngine.ini(project settings); it mutst be LcAssetManager"));

	// ���� UE_LOG�� Fatal�� ����, Crash�� �߻��ϹǷ�, �Ʒ� �ڵ�� ������� ���� ������ �������� ���� ���̷� �����մϴ�.
	return *NewObject<ULcAssetManager>();
}

PRAGMA_DISABLE_OPTIMIZATION 
void ULcAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	FLcGameplayTags::InitializeNativeTags();
}
PRAGMA_ENABLE_OPTIMIZATION

bool ULcAssetManager::ShouldLogAssetLoads()
{
	const TCHAR* CommandLineContent = FCommandLine::Get();
	static bool bLogAssetLoads = FParse::Param(CommandLineContent, TEXT("LogAssetLoads"));
	return bLogAssetLoads;
}

UObject* ULcAssetManager::SynchronousLoadAsset(const FSoftObjectPath& AssetPath)
{
	// �ش� �Լ��� ���� ���� ������ 'synchronous load asset�� ���ʿ��ϰ� �ϴ� ���� ������ Ȯ���ϱ� ����'
	if (AssetPath.IsValid())
	{
		// FScopeLogTime�� Ȯ���غ���:
		TUniquePtr<FScopeLogTime> LogTimePtr;
		if (ShouldLogAssetLoads())
		{
			// �ܼ��� �α��ϸ鼭, �ʴ����� �α� ����
			LogTimePtr = MakeUnique<FScopeLogTime>(*FString::Printf(TEXT("synchronous loaded assets [%s]"), *AssetPath.ToString()), nullptr, FScopeLogTime::ScopeLog_Seconds);
		}

		// ���⼭ �ΰ��� �б�:
		// 1. AssetManager�� ������, AssetManager�� StreamableManager�� ���� ���� �ε�
		// 2. �ƴϸ�, FSoftObjectPath�� ���� �ٷ� ���� �ε�
		if (UAssetManager::IsValid())
		{
			return UAssetManager::GetStreamableManager().LoadSynchronous(AssetPath);
		}

		// if asset manager is not ready, use LoadObject()
		// - �� ����, StaticLoadObject�� ���δ�: 
		// - �����, �׻� StaticLoadObject�ϱ� ���� StaticFindObject�� ���� Ȯ���ϰ� �����ϸ� ��¥ �ε���
		return AssetPath.TryLoad();
	}

	return nullptr;
}

void ULcAssetManager::AddLoadedAsset(const UObject* Asset)
{
	if (ensureAlways(Asset))
	{
		FScopeLock Lock(&SyncObject);
		LoadedAssets.Add(Asset);
	}
}
