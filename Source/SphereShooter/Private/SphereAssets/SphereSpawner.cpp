// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereShooter/Public/SphereAssets/SphereSpawner.h"

#include "Kismet/KismetMathLibrary.h"

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
	for(int i = 0; i < Quantity; i++)
	{
		ASphereActor* SphereActor = NewObject<ASphereActor>(this);
		SphereActor->AttachToComponent(Root, FAttachmentTransformRules::KeepWorldTransform);
	}
	
}

// Called every frame
void ASphereSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

