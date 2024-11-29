// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterBase.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.0f;
	CameraBoom->bUsePawnControlRotation = true;
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	HUDWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HUD"));
	HUDWidget->SetupAttachment(RootComponent);
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (PlayerInputComponent)
	{
		PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacterBase::Jump);
		PlayerInputComponent->BindAxis("MoveForward", this, &ACharacterBase::MoveForward);
		PlayerInputComponent->BindAxis("Turn", this, &ACharacterBase::Turn);
		PlayerInputComponent->BindAxis("LookUp", this, &ACharacterBase::LookUp);
		PlayerInputComponent->BindAxis("MoveRight", this, &ACharacterBase::MoveRight);
	}
}
void ACharacterBase::MoveForward(float Value)
{
	if (Controller!=nullptr && Value != 0.0f)
	{
		const FRotator YawRotation(0.f,Controller->GetControlRotation().Yaw,0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Value);
	}
}

void ACharacterBase::MoveRight(float Value)
{
	if (Controller!=nullptr && Value != 0.0f)
	{
		const FRotator YawRotation(0.f,Controller->GetControlRotation().Yaw,0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, Value);
	}
}

void ACharacterBase::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ACharacterBase::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


