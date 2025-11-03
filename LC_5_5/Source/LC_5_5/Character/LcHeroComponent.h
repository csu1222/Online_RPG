// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkInitStateInterface.h"
#include "Components/PawnComponent.h"
#include "LC_5_5/Input/LcMappableConfigPair.h"
#include "LcHeroComponent.generated.h"

class ULcCameraMode;
/**
 * 
 */
UCLASS(Blueprintable, Meta = (BlueprintSpawnableComponent))
class LC_5_5_API ULcHeroComponent : public UPawnComponent, public IGameFrameworkInitStateInterface
{
	GENERATED_BODY()
public:
	ULcHeroComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	/** FeatureName Á¤ÀÇ */
	static const FName NAME_ActorFeatureName;

	/**
	 * UPawnComponent interface
	 */
	virtual void OnRegister() final;
	virtual void BeginPlay() final;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) final;

	/**
	* IGameFrameworkInitStateInterface
	*/
	virtual FName GetFeatureName() const final { return NAME_ActorFeatureName; }
	virtual void OnActorInitStateChanged(const FActorInitStateChangedParams& Params) final;
	virtual bool CanChangeInitState(UGameFrameworkComponentManager* Manager, FGameplayTag CurrentState, FGameplayTag DesiredState) const final;
	virtual void HandleChangeInitState(UGameFrameworkComponentManager* Manager, FGameplayTag CurrentState, FGameplayTag DesiredState) final;
	virtual void CheckDefaultInitialization() final;

	/**
	 * member methods
	 */
	TSubclassOf<ULcCameraMode> DetermineCameraMode() const;

	/**
	* member variables
	*/
	UPROPERTY(EditAnywhere)
	TArray<FLcMappableConfigPair> DefaultInputConfigs;
};
