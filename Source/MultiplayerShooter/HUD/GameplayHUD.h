// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayHUD.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYERSHOOTER_API UGameplayHUD : public UCommonActivatableWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta=(BindWidget))
	class UCommonTextBlock* DisplayText;

	UFUNCTION()
	void SetDisplayText(const FString& TextDisplayText);

	UFUNCTION(BlueprintCallable)
	void ShowPlayerNetRole(APawn* InPawn);
protected:
	virtual void RemoveFromParent() override;
	
};
