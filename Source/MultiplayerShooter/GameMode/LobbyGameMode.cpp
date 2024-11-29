// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	int32 NumberOfPlayer = GameState->PlayerArray.Num();
	if (NumberOfPlayer > 1)
	{
		if (UWorld* World = GetWorld())
		{
			bUseSeamlessTravel = true;
			World->ServerTravel(FString("/Game/Maps/BaseMap?listen"));
		}
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}
