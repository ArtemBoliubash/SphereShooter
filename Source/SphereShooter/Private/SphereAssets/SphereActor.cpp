// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereShooter/Public/SphereAssets/SphereActor.h"
#include "NiagaraFunctionLibrary.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "SphereAssets/SphereSpawner.h"

// Sets default values
ASphereActor::ASphereActor()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	
	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMesh"));
	SphereMesh->SetupAttachment(RootComponent);
	
	//Disable tick
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
	if( GetGameInstance() )
	{
		USphereSpawner* SphereSpawner = GetGameInstance()->GetSubsystem<USphereSpawner>();
		SphereSpawner->WaveQuantityDestroyedSpheres += 1;
		SphereSpawner->AllQuantityDestroyedSpheres += 1;
		SphereSpawner->OnQuantityDestroyedSpheresChanges();
		SphereSpawner->OnQuantityDestroyedSpheresChange.Broadcast();
		const float ParticleSize = SphereSpawner->ParticleSize - SphereSpawner->CurrentSize;
		if( UParticleSystem* ParticleSystem = Cast< UParticleSystem >( SphereSpawner->Particle ) )
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticleSystem, GetActorLocation() )->SetWorldScale3D( FVector( ParticleSize ) );
		}
		 else if( UNiagaraSystem* NiagaraSystem = Cast< UNiagaraSystem >( SphereSpawner->Particle ) )
		{
		 	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraSystem, GetActorLocation(), FRotator::ZeroRotator, FVector( ParticleSize ) );
		}

		//Spawn Chaos Object
		FActorSpawnParameters SpawnInfo;
		AGeometryCollectionActor* GeometryCollectionActor = GetWorld()->SpawnActor< AGeometryCollectionActor >( ChaosClass.Get(), GetActorLocation(), FRotator(), SpawnInfo );
		GeometryCollectionActor->SetActorScale3D( FVector( SphereSpawner->CurrentSize ));
	}
}

// Called every frame
void ASphereActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

