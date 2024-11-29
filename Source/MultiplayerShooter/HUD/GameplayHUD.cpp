// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayHUD.h"
#include "CommonTextBlock.h"

void UGameplayHUD::SetDisplayText(const FString& TextDisplayText)
{
	if (IsValid(DisplayText))
	{
		DisplayText->SetText(FText::FromString(TextDisplayText));
	}
}

void UGameplayHUD::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	FString Role;
	switch (LocalRole)
	{
	case ROLE_Authority:
		Role = FString("Authority");
		break;
	case ROLE_AutonomousProxy:
		Role = FString("AutonomousProxy");
		break;
	case ROLE_SimulatedProxy:
		Role = FString("SimulatedProxy");
		break;
	case ROLE_None:
		Role = FString("None");
		break;
	case ROLE_MAX:
		Role = FString("Max");
		break;
	}
	FString LocalRoleString = FString::Printf(TEXT("Local Role: %s"), *Role);
	SetDisplayText(LocalRoleString);
}

void UGameplayHUD::RemoveFromParent()
{
	
	Super::RemoveFromParent();
}
