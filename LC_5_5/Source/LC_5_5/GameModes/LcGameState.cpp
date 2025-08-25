// Fill out your copyright notice in the Description page of Project Settings.


#include "LcGameState.h"
#include "LcExperienceManagerComponent.h"

ALcGameState::ALcGameState()
{
	ExperienceManagerComponent = CreateDefaultSubobject<ULcExperienceManagerComponent>(TEXT("ExperienceManagerComponent"));
}
