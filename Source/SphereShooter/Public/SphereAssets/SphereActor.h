// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereActor.generated.h"

class USphereComponent;
class ASphereSpawner;

UCLASS()
class SPHERESHOOTER_API ASphereActor : public AActor
{
	GENERATED_BODY()

public:
	
	ASphereActor();
	
	//Root
	UPROPERTY( BlueprintReadOnly, Category = "Components")
	USceneComponent* Root;
	
	//Mesh sphere
	UPROPERTY(BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* SphereMesh;

	//Collision sphere
	UPROPERTY(BlueprintReadOnly, Category = "Components")
	USphereComponent* SphereComponent;

	virtual void BeginPlay() override;
	virtual void Destroyed() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
