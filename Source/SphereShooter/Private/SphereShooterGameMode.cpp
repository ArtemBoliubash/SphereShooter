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

	USphereSpawner* SphereSpawner = GetGameInstance()->GetSubsystem<USphereSpawner>();

	SphereSpawner->Radius = Radius;
	
	SphereSpawner->Quantity = Quantity;

	SphereSpawner->SphereClass = SphereClass;
	
	SphereSpawner->Particle = Particle;
	
	SphereSpawner->ParticleSize = ParticleSize;

	SphereSpawner->MinSize = MinSize;
	
	SphereSpawner->ChangeSizeStep = ChangeSizeStep;
	
	SphereSpawner->NewWaveQuantity = NewWaveQuantity;
	
	SphereSpawner->SpawnFirstWave();
}
