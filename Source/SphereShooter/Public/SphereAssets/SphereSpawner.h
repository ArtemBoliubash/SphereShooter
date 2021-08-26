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
	UPROPERTY(BlueprintReadWrite)
	int32 QuantityDestroyedSpheres;
	UPROPERTY(BlueprintAssignable)
	FOnQuantityDestroyedSpheresChange OnQuantityDestroyedSpheresChange;

protected:
	// Called when the game starts or when spawned
	UPROPERTY(BlueprintReadOnly, Category = "Components")
	class USceneComponent* Root;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Quantity;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Radius;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh* SphereMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class ASphereShooterCharacter* Player;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void SpawnSpheres(int32 IncreasingNumberSpheres, int32 IncreasingRadius);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
