// Fill out your copyright notice in the Description page of Project Settings.


#include "LcCharacter.h"
#include "LcPawnExtensionComponent.h"
#include "LcCameraComponent.h"

// Sets default values
ALcCharacter::ALcCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	// PawnExtensionComponent ����
	PawnExtComponent = CreateDefaultSubobject<ULcPawnExtensionComponent>(TEXT("PawnExtensionComponent"));

	// CameraComponent ����
	{
		CameraComponent = CreateDefaultSubobject<ULcCameraComponent>(TEXT("CameraComponent"));
		CameraComponent->SetRelativeLocation(FVector(-300.0f, 0.0f, 75.0f));
	}
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

	// Pawn�� Possess�μ�, Controller�� PlayerState ���� ������ ������ ���°� �Ǿ���
	// - SetupPlayerInputComponent Ȯ�� 
	PawnExtComponent->SetupPlayerInputComponent();
}

