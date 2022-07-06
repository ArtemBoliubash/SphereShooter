// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SphereShooterGameMode.generated.h"

UCLASS(minimalapi)
class ASphereShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASphereShooterGameMode();

	UPROPERTY( EditAnywhere )
	int Quantity;

	UPROPERTY( EditAnywhere )
	int Radius;

	UPROPERTY( EditAnywhere )
	int NewWaveQuantity;
	
	UPROPERTY( EditAnywhere )
	UStaticMesh* SphereMesh;

	UPROPERTY( EditAnywhere )
	UParticleSystem* Particle;

	virtual void BeginPlay() override;
};



