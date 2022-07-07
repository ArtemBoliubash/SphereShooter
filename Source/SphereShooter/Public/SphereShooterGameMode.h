// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Particles/ParticleSystem.h"
#include "SphereShooterGameMode.generated.h"

class ASphereActor;

UCLASS(minimalapi)
class ASphereShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASphereShooterGameMode();

	UPROPERTY( EditAnywhere )
	int Quantity = 15;

	UPROPERTY( EditAnywhere )
	int Radius = 2000;

	UPROPERTY( EditAnywhere )
	float MinSize= 1.f;

	UPROPERTY( EditAnywhere )
	float ChangeSizeStep= 1.f;

	UPROPERTY( EditAnywhere )
	int NewWaveQuantity = 10;
	
	UPROPERTY( EditAnywhere )
	UFXSystemAsset* Particle;

	UPROPERTY( EditAnywhere )
	float ParticleSize = 1.f;
	
	UPROPERTY( EditAnywhere )
	TSubclassOf< ASphereActor > SphereClass;

	virtual void BeginPlay() override;
};



