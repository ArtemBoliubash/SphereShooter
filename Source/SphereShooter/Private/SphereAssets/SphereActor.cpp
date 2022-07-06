// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereShooter/Public/SphereAssets/SphereActor.h"

#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SphereAssets/SphereSpawner.h"

// Sets default values
ASphereActor::ASphereActor()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(Root);

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(SphereMesh);
	SphereComponent->SetSphereRadius( 124 );
	SphereComponent->SetCollisionProfileName( "BlockAll" );
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASphereActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASphereActor::Destroyed()
{
	Super::Destroyed();
	//Transferring information about destruction to the spawner
	GetGameInstance()->GetSubsystem<USphereSpawner>()->WaveQuantityDestroyedSpheres += 1;
	GetGameInstance()->GetSubsystem<USphereSpawner>()->AllQuantityDestroyedSpheres += 1;
	GetGameInstance()->GetSubsystem<USphereSpawner>()->OnQuantityDestroyedSpheresChanges();
	GetGameInstance()->GetSubsystem<USphereSpawner>()->OnQuantityDestroyedSpheresChange.Broadcast();
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), GetGameInstance()->GetSubsystem<USphereSpawner>()->Particle, GetActorLocation());
}

// Called every frame
void ASphereActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

