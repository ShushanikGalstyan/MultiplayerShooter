// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CharacterBase.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Character = Cast<ACharacterBase>(TryGetPawnOwner());
}

void UCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (Character == nullptr)
	{
		Character = Cast<ACharacterBase>(TryGetPawnOwner());
	}
	if (Character == nullptr) return;
	FVector Velocity = Character->GetVelocity();
	Velocity.Z = 0.f;
	Speed =  Velocity.Size();

	bIsInAir = Character->GetCharacterMovement()->IsFalling();
	bIsAccelerating = Character->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f;
}
