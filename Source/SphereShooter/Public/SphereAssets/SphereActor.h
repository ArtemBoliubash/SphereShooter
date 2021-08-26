// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SphereActor.generated.h"

UCLASS()
class SPHERESHOOTER_API ASphereActor : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Destroyed() override;
	UPROPERTY(BlueprintReadOnly, Category = "Components")
	class USceneComponent* Root;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	class UStaticMeshComponent* SphereMesh;
	
public:
	ASphereActor();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
