// Copyright Epic Games, Inc. All Rights Reserved.

#include "SphereShooter/Public/SphereShooterGameMode.h"

#include "UObject/ConstructorHelpers.h"

ASphereShooterGameMode::ASphereShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	
}
