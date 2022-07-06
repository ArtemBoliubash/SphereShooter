// Copyright Epic Games, Inc. All Rights Reserved.

#include "SphereShooter/Public/SphereShooterGameMode.h"

#include "SphereAssets/SphereSpawner.h"
#include "UObject/ConstructorHelpers.h"

ASphereShooterGameMode::ASphereShooterGameMode()
	: Super()
{
}

void ASphereShooterGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetGameInstance()->GetSubsystem<USphereSpawner>()->Radius = Radius;
	
	GetGameInstance()->GetSubsystem<USphereSpawner>()->Quantity = Quantity;
	
	GetGameInstance()->GetSubsystem<USphereSpawner>()->SphereMesh = SphereMesh;
	
	GetGameInstance()->GetSubsystem<USphereSpawner>()->Particle = Particle;
	
	GetGameInstance()->GetSubsystem<USphereSpawner>()->NewWaveQuantity = NewWaveQuantity;
	
	GetGameInstance()->GetSubsystem<USphereSpawner>()->SpawnFirstWave();
}
