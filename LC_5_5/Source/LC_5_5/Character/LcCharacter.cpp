// Fill out your copyright notice in the Description page of Project Settings.


#include "LcCharacter.h"
#include "LcPawnExtensionComponent.h"

// Sets default values
ALcCharacter::ALcCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	PawnExtComponent = CreateDefaultSubobject<ULcPawnExtensionComponent>(TEXT("PawnExtensionComponent"));
}

// Called when the game starts or when spawned
void ALcCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALcCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALcCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Pawn이 Possess로서, Controller와 PlayerState 정보 접근이 가능한 상태가 되었음
	// - SetupPlayerInputComponent 확인 
	PawnExtComponent->SetupPlayerInputComponent();
}

