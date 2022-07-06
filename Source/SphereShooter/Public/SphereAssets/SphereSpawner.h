// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SphereSpawner.generated.h"

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
	int WaveQuantityDestroyedSpheres = 0.f;
	//Bind to change the number of destroyed spheres
	UPROPERTY(BlueprintAssignable)
	FOnQuantityDestroyedSpheresChange OnQuantityDestroyedSpheresChange;
	//Spawns when sphere destroy
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UParticleSystem* Particle;
	
	UPROPERTY(BlueprintReadOnly)
	int NewWaveQuantity = 0.f;

	UPROPERTY(BlueprintReadOnly)
	int Wave = 1.f;

	UPROPERTY(BlueprintReadOnly)
	int AllQuantityDestroyedSpheres = 0.f;

	//Starting number of spheres
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Quantity;
	//Spawn radius
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Radius;

	//Mesh sphere
	UPROPERTY( Transient )
	UStaticMesh* SphereMesh;
	
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