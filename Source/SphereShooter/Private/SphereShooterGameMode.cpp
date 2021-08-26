// Copyright Epic Games, Inc. All Rights Reserved.

#include "SphereShooter/Public/SphereShooterGameMode.h"

#include "SphereShooter/Public/UI/SphereShooterHUD.h"
#include "UObject/ConstructorHelpers.h"

ASphereShooterGameMode::ASphereShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ASphereShooterHUD::StaticClass();
}
