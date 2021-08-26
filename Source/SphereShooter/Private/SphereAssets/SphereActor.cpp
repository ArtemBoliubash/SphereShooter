// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereShooter/Public/SphereAssets/SphereActor.h"

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
}

// Called every frame
void ASphereActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

