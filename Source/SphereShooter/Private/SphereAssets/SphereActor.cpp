// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereShooter/Public/SphereAssets/SphereActor.h"

#include "Kismet/GameplayStatics.h"
#include "SphereAssets/SphereSpawner.h"

// Sets default values
ASphereActor::ASphereActor()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(Root);
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASphereActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASphereActor::Destroyed()
{
	Super::Destroyed();
	Spawner->QuantityDestroyedSpheres += 1;
	Spawner->OnQuantityDestroyedSpheresChange.Broadcast();
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Spawner->Particle, GetActorLocation());
}

// Called every frame
void ASphereActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

