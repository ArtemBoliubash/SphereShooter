// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SphereSpawner.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQuantityDestroyedSpheresChange);

UCLASS()
class SPHERESHOOTER_API ASphereSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASphereSpawner();
	//Serves to refresh the wave
	UPROPERTY(BlueprintReadWrite)
	int32 QuantityDestroyedSpheres;
	//Bind to change the number of destroyed spheres
	UPROPERTY(BlueprintAssignable)
	FOnQuantityDestroyedSpheresChange OnQuantityDestroyedSpheresChange;
	//Spawns when sphere destroy
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UParticleSystem* Particle;
	
protected:
	// Called when the game starts or when spawned
	UPROPERTY(BlueprintReadOnly, Category = "Components")
	class USceneComponent* Root;
	//Starting number of spheres
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Quantity;
	//Spawn radius
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Radius;
	//Mesh sphere
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh* SphereMesh;
	//Pointer to the player to spawn new waves
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class ASphereShooterCharacter* Player;
	virtual void BeginPlay() override;

	//Function for creating a new wave
	UFUNCTION(BlueprintCallable)
	void SpawnSpheres(int32 IncreasingNumberSpheres, int32 IncreasingRadius);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
