// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GGJ_RoombaGameMode.h"
#include "GGJ_RoombaPlayerController.h"
#include "GGJ_RoombaCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGGJ_RoombaGameMode::AGGJ_RoombaGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGGJ_RoombaPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}