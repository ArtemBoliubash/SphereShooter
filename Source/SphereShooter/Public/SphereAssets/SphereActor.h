// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeometryCollection/GeometryCollectionActor.h"
#include "SphereActor.generated.h"

class USphereComponent;
class ASphereSpawner;
class URadialFalloff;
class UFieldSystemComponent;

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
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* SphereMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Chaos")
	TSubclassOf< AGeometryCollectionActor > ChaosClass;

	virtual void BeginPlay() override;
	
	virtual void Destroyed() override;
	

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
