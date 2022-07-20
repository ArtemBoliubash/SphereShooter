// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particles/ParticleSystem.h"
#include "SphereSpawner.generated.h"

class ASphereActor;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQuantityDestroyedSpheresChange);

UCLASS()
class SPHERESHOOTER_API USphereSpawner : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	USphereSpawner();
	//Serves to refresh the wave
	UPROPERTY(BlueprintReadWrite)
	int WaveQuantityDestroyedSpheres = 0;
	//Bind to change the number of destroyed spheres
	UPROPERTY(BlueprintAssignable)
	FOnQuantityDestroyedSpheresChange OnQuantityDestroyedSpheresChange;
	//Spawns when sphere destroy
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UFXSystemAsset* Particle;

	float ParticleSize;
	
	float MinSize = 0.1f;
	
	float ChangeSizeStep = 0.1f;

	float CurrentSize = 1.f;
	
	UPROPERTY(BlueprintReadOnly)
	int NewWaveQuantity = 0;

	UPROPERTY(BlueprintReadOnly)
	int Wave = 1;

	UPROPERTY(BlueprintReadOnly)
	int AllQuantityDestroyedSpheres = 0;

	UPROPERTY(BlueprintReadOnly)
	bool bIsPlayerWon = false;

	//Starting number of spheres
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Quantity;
	//Spawn radius
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Radius;

	//Mesh sphere
	UPROPERTY( Transient )
	TSubclassOf< ASphereActor > SphereClass;
	
	void SpawnFirstWave();

	void OnQuantityDestroyedSpheresChanges();
	
protected:
	
	//Pointer to the player to spawn new waves
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class ASphereShooterCharacter* Player;
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
	
	//Function for creating a new wave
	UFUNCTION(BlueprintCallable)
	void SpawnSpheres(int32 IncreasingNumberSpheres, int32 IncreasingRadius);
	
};