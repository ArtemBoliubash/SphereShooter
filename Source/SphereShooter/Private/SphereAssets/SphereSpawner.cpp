// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereShooter/Public/SphereAssets/SphereSpawner.h"

#include "SphereShooterGameMode.h"
#include "Character/SphereShooterCharacter.h"
#include "NavigationSystem.h"
#include "SphereAssets/SphereActor.h"

// Sets default values
USphereSpawner::USphereSpawner()
{
}

void USphereSpawner::OnQuantityDestroyedSpheresChanges()
{
	if( WaveQuantityDestroyedSpheres >= NewWaveQuantity )
	{
		SpawnSpheres( 10, 5 );
		WaveQuantityDestroyedSpheres = 0;
		NewWaveQuantity += NewWaveQuantity / 10;
		Wave++;
	}
}

void USphereSpawner::SpawnSpheres(int32 IncreasingNumberSpheres, int32 IncreasingRadius)
{
	FActorSpawnParameters SpawnInfo;
	Quantity += Quantity*IncreasingNumberSpheres/100;
	Radius += Radius*IncreasingRadius/100;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	for(int i = 0; i < Quantity; i++)
	{
		AActor* SpawnedSphere =  GetWorld()->SpawnActor<ASphereActor>(FVector(Player->GetActorLocation().X + FMath::VRand().X *FMath::RandRange(0,Radius), Player->GetActorLocation().Y + FMath::VRand().Y * FMath::RandRange(0,Radius), Player->GetActorLocation().Z + FMath::RandRange(0,Radius)), FRotator(0,0,0), SpawnInfo);
		Cast<ASphereActor>(SpawnedSphere)->SphereMesh->SetStaticMesh(SphereMesh);
	}
	
}

void USphereSpawner::SpawnFirstWave()
{
	Player = Cast<ASphereShooterCharacter>( GetWorld()->GetFirstPlayerController()->GetPawn() );
	//Spawn firs wave
	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
	for(int i = 0; i < Quantity; i++)
	{
		AActor* SpawnedSphere =  GetWorld()->SpawnActor<ASphereActor>(FVector(Player->GetActorLocation().X + FMath::VRand().X *FMath::RandRange(0,Radius), Player->GetActorLocation().Y + FMath::VRand().Y * FMath::RandRange(0,Radius), Player->GetActorLocation().Z + FMath::RandRange(0,Radius)), FRotator(0,0,0), SpawnInfo);
		if( SpawnedSphere )
		{
			Cast<ASphereActor>(SpawnedSphere)->SphereMesh->SetStaticMesh(SphereMesh);
		}
	}
}

void USphereSpawner::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void USphereSpawner::Deinitialize()
{
	Super::Deinitialize();
}
