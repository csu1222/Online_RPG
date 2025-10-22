// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/LcCameraMode.h"
#include "LcCameraMode_ThirdPerson.generated.h"

class UCurveVector;

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class LC_5_5_API ULcCameraMode_ThirdPerson : public ULcCameraMode
{
	GENERATED_BODY()
public:
	ULcCameraMode_ThirdPerson(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
	/*
		ULcCameraMode's interface
	*/
	virtual void UpdateView(float DeltaTime) override;

	/**
	* member variables
	*/
	UPROPERTY(EditDefaultsOnly, Category = "Third Person")
	TObjectPtr<const UCurveVector> TargetOffsetCurve;
};
