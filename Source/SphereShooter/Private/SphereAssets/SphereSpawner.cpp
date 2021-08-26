// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereShooter/Public/SphereAssets/SphereSpawner.h"

#include "Character/SphereShooterCharacter.h"
#include "SphereAssets/SphereActor.h"

// Sets default values
ASphereSpawner::ASphereSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASphereSpawner::BeginPlay()
{
	Super::BeginPlay();
	//Spawn firs wave
	FActorSpawnParameters SpawnInfo;
	for(int i = 0; i < Quantity; i++)
	{
		AActor* SpawnedSphere =  GetWorld()->SpawnActor<ASphereActor>(FVector(Player->GetActorLocation().X + FMath::VRand().X *FMath::RandRange(0,Radius), Player->GetActorLocation().Y + FMath::VRand().Y * FMath::RandRange(0,Radius), Player->GetActorLocation().Z + FMath::RandRange(0,Radius)), FRotator(0,0,0), SpawnInfo);
		Cast<ASphereActor>(SpawnedSphere)->SphereMesh->SetStaticMesh(SphereMesh);
		Cast<ASphereActor>(SpawnedSphere)->Spawner = this;
	}
	
}

void ASphereSpawner::SpawnSpheres(int32 IncreasingNumberSpheres, int32 IncreasingRadius)
{
	FActorSpawnParameters SpawnInfo;
	Quantity += Quantity*IncreasingNumberSpheres/100;
	Radius += Radius*IncreasingRadius/100;
	for(int i = 0; i < Quantity; i++)
	{
		AActor* SpawnedSphere =  GetWorld()->SpawnActor<ASphereActor>(FVector(Player->GetActorLocation().X + FMath::VRand().X *FMath::RandRange(0,Radius), Player->GetActorLocation().Y + FMath::VRand().Y * FMath::RandRange(0,Radius), Player->GetActorLocation().Z + FMath::RandRange(0,Radius)), FRotator(0,0,0), SpawnInfo);
		Cast<ASphereActor>(SpawnedSphere)->SphereMesh->SetStaticMesh(SphereMesh);
		Cast<ASphereActor>(SpawnedSphere)->Spawner = this;
	}
	
}

// Called every frame
void ASphereSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

