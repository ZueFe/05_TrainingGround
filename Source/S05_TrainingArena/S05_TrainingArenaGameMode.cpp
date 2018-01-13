// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "S05_TrainingArenaGameMode.h"
#include "S05_TrainingArenaHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AS05_TrainingArenaGameMode::AS05_TrainingArenaGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_TrainingArenaHUD::StaticClass();
}
