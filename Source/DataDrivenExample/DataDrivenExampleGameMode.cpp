// Copyright Epic Games, Inc. All Rights Reserved.

#include "DataDrivenExampleGameMode.h"
#include "DataDrivenExampleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADataDrivenExampleGameMode::ADataDrivenExampleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
