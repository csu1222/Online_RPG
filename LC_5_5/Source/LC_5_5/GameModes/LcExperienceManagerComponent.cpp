// Fill out your copyright notice in the Description page of Project Settings.


#include "LcExperienceManagerComponent.h"
#include "GameFeaturesSubsystemSettings.h"
#include "LcExperienceDefinition.h"
#include "LC_5_5/System/LcAssetManager.h"

void ULcExperienceManagerComponent::CallOrRegister_OnExperienceLoaded(FOnLcExperienceLoaded::FDelegate&& Delegate)
{
	// IsExperienceLoaded() ����
	if (IsExperienceLoaded())
	{
		Delegate.Execute(CurrentExperience);
	}
	else
	{
		/**
		 * �����, �����е��� Delegate ��ü�� �ڼ��� ���캸��, ���������� �ʿ��� �������� �޸� �Ҵ��س��´�:
		 * TArray<int> a = {1, 2, 3, 4};
		 * delegate_type delegate = [a](){
		 *	return a.Num();
		 * }
		 * a�� delegate_type ���ο� new�� �Ҵ�Ǿ� �ִ�. ���� ����� ���߱� ���� Move�� ���� �ϴ� ���� ���� ����!
		 */
		OnExperienceLoaded.Add(MoveTemp(Delegate));
	}
}

void ULcExperienceManagerComponent::ServerSetCurrentExperience(FPrimaryAssetId ExperienceId)
{
	ULcAssetManager& AssetManager = ULcAssetManager::Get();

	TSubclassOf<ULcExperienceDefinition> AssetClass;
	{
		FSoftObjectPath AssetPath = AssetManager.GetPrimaryAssetPath(ExperienceId);
		AssetClass = Cast<UClass>(AssetPath.TryLoad());
	}

	// �� CDO�� �������� �ɱ�?
	const ULcExperienceDefinition* Experience = GetDefault<ULcExperienceDefinition>(AssetClass);
	check(Experience != nullptr);
	check(CurrentExperience == nullptr);
	{
		// �׸��� CDO�� CurrentExperience�� �����Ѵ�!
		// � �ǵ��� �̷��� �ڵ带 �ۼ������� �ڵ带 �� �о��(StartExperienceLoad���� �о��) �ٽ� �����غ���:
		CurrentExperience = Experience;
	}

	StartExperienceLoad();
}

PRAGMA_DISABLE_OPTIMIZATION
void ULcExperienceManagerComponent::StartExperienceLoad()
{
	check(CurrentExperience);
	check(LoadState == ELcExperienceLoadState::Unloaded);

	LoadState = ELcExperienceLoadState::Loading;

	ULcAssetManager& AssetManager = ULcAssetManager::Get();

	// �̹� �ռ�, ServerSetCurrentExperience���� �츮�� ExperienceId�� �Ѱ��־��µ�, ���⼭ CDO�� Ȱ���Ͽ�, GetPrimaryAssetId�� �ε��� ������� �ִ´�!
	// - �� �̷��� �ϴ°ɱ�?
	// - GetPrimaryAssetId�� �� �� �ڼ�������:
	// - GetPrimaryAssetId�� ���캽���ν�, �Ʒ��� �ΰ����� �� �� �ִ�:
	//   1. �츮�� B_LcDefaultExperience�� BP�� ���� ����
	//   2. CDO�� �����ͼ�, GetPrimaryAssetId�� ȣ���� ����

	// �츮�� �ռ� �̹� CDO�� �ε��Ͽ�, CDO�� ������� �ʰ� CDO�� ����Ͽ� �ε��� ������ �����Ͽ�, BundleAssetList�� �߰����ش�!

	TSet<FPrimaryAssetId> BundleAssetList;
	BundleAssetList.Add(CurrentExperience->GetPrimaryAssetId());

	// load assets associated with the experience
	// �Ʒ��� �츮�� ���� GameFeature�� ����Ͽ�, Experience�� ���ε��� GameFeature Plugin�� �ε��� Bundle �̸��� �߰��Ѵ�:
	// - Bundle�̶�°� ���� �츮�� �ε��� ������ ī�װ� �̸��̶�� �����ϸ� �ȴ� (�ϴ� ������ �Ѿ�� ����, �� �ٷ� ���̴�!)
	TArray<FName> BundlesToLoad;
	{
		// ���⼭ �ָ��ؾ� �� �κ��� OwnerNetMode�� NM_Standalone�̸�? Client/Server �Ѵ� �ε��� �߰��ȴ�!
		const ENetMode OwnerNetMode = GetOwner()->GetNetMode();
		bool bLoadClient = GIsEditor || (OwnerNetMode != NM_DedicatedServer);
		bool bLoadServer = GIsEditor || (OwnerNetMode != NM_Client);
		if (bLoadClient)
		{
			BundlesToLoad.Add(UGameFeaturesSubsystemSettings::LoadStateClient);
		}
		if (bLoadServer)
		{
			BundlesToLoad.Add(UGameFeaturesSubsystemSettings::LoadStateServer);
		}
	}

	FStreamableDelegate OnAssetsLoadedDelegate = FStreamableDelegate::CreateUObject(this, &ThisClass::OnExperienceLoadComplete);

	// �Ʒ���, ���� Bundle�� �츮�� GameFeature�� �����ϸ鼭 �� ��� �˾ƺ���� �ϰ�, ������ �ռ� B_LcDefaultExperience�� �ε����ִ� �Լ��� ��������
	TSharedPtr<FStreamableHandle> Handle = AssetManager.ChangeBundleStateForPrimaryAssets(
		BundleAssetList.Array(),
		BundlesToLoad,
		{}, false, FStreamableDelegate(), FStreamableManager::AsyncLoadHighPriority);

	if (!Handle.IsValid() || Handle->HasLoadCompleted())
	{
		// �ε��� �Ϸ�Ǿ�����, ExecuteDelegate�� ���� OnAssetsLoadedDelegate�� ȣ������:
		// - �Ʒ��� �Լ��� Ȯ���غ���:
		FStreamableHandle::ExecuteDelegate(OnAssetsLoadedDelegate);
	}
	else
	{
		Handle->BindCompleteDelegate(OnAssetsLoadedDelegate);
		Handle->BindCancelDelegate(FStreamableDelegate::CreateLambda([OnAssetsLoadedDelegate]()
			{
				OnAssetsLoadedDelegate.ExecuteIfBound();
			}));
	}

	// FrameNumber�� �ָ��ؼ� ����
	static int32 StartExperienceLoad_FrameNumber = GFrameNumber;
}
PRAGMA_ENABLE_OPTIMIZATION

void ULcExperienceManagerComponent::OnExperienceLoadComplete()
{
	// FrameNumber�� �ָ��ؼ� ����
	static int32 OnExperienceLoadComplete_FrameNumber = GFrameNumber;

	// �ش� �Լ��� �Ҹ��� ���� �ռ� ���Ҵ� StreamableDelegateDelayHelper�� ���� �Ҹ�
	OnExperienceFullLoadCompleted();
}

void ULcExperienceManagerComponent::OnExperienceFullLoadCompleted()
{
	check(LoadState != ELcExperienceLoadState::Loaded);

	LoadState = ELcExperienceLoadState::Loaded;
	OnExperienceLoaded.Broadcast(CurrentExperience);
	OnExperienceLoaded.Clear();
}

const ULcExperienceDefinition* ULcExperienceManagerComponent::GetCurrentExperienceChecked() const
{
	check(LoadState == ELcExperienceLoadState::Loaded);
	check(CurrentExperience != nullptr);
	return CurrentExperience;
}