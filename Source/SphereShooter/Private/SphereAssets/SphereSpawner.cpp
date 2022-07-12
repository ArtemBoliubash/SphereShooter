// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereShooter/Public/SphereAssets/SphereSpawner.h"

#include "SphereShooterGameMode.h"
#include "Character/SphereShooterCharacter.h"
#include "NavigationSystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "SphereAssets/SphereActor.h"

// Sets default values
USphereSpawner::USphereSpawner()
{
}
//Calls when sphere destroys
void USphereSpawner::OnQuantityDestroyedSpheresChanges()
{
	if( WaveQuantityDestroyedSpheres >= NewWaveQuantity )
	{
		//Spawn new wave and clear intermediate values
		SpawnSpheres( 10, 5 );
		WaveQuantityDestroyedSpheres = 0;
		NewWaveQuantity += NewWaveQuantity / 10;
		Wave++;
	}
}

void USphereSpawner::SpawnSpheres(int32 IncreasingNumberSpheres, int32 IncreasingRadius)
{
	FActorSpawnParameters SpawnInfo;
	Quantity += Quantity * IncreasingNumberSpheres / 100;
	Radius += Radius * IncreasingRadius / 100;
	if( MinSize < CurrentSize && !FMath::IsNearlyEqual( MinSize, CurrentSize,  1E-03) )
	{
		CurrentSize -= ChangeSizeStep;
	}
	for(int i = 0; i < Quantity; i++)
	{
		// 100 tries
		for( int j = 0; j < 100; j++ )
		{
			//Find Random Position in World
			FVector RandPos = FVector(Player->GetActorLocation().X + FMath::VRand().X * FMath::RandRange(0,Radius), Player->GetActorLocation().Y + FMath::VRand().Y * FMath::RandRange(0,Radius),Player->GetActorLocation().Z + FMath::RandRange(0,Radius));
			//Empty Array Of Actors To Ignore
			TArray<AActor*> Array;
			
			FHitResult HitResult;
			//Check Is Can Spawn Sphere
			if ( UKismetSystemLibrary::SphereTraceSingle( GetWorld(), RandPos, RandPos,  SphereClass.GetDefaultObject()->SphereMesh->GetStaticMesh()->GetBounds().GetBox().GetSize().Size(),
				ETraceTypeQuery::TraceTypeQuery1, false, Array, EDrawDebugTrace::None, HitResult, false))
			{
			}
			else
			{
				ASphereActor* SphereActor = GetWorld()->SpawnActor<ASphereActor>( SphereClass.Get(), RandPos, FRotator(0,0,0), SpawnInfo);
				SphereActor->SetActorScale3D( FVector ( CurrentSize ) );
				SphereActor->CurrentSize = CurrentSize;
				break;
			}
		}
	}
	
}

void USphereSpawner::SpawnFirstWave()
{
	Player = Cast<ASphereShooterCharacter>( GetWorld()->GetFirstPlayerController()->GetPawn() );
	FActorSpawnParameters SpawnInfo;
	for(int i = 0; i < Quantity; i++)
	{
		// 100 tries
		for( int j = 0; j < 100; j++ )
		{
			//Find Random Position in World
			FVector RandPos = FVector(Player->GetActorLocation().X + FMath::VRand().X * FMath::RandRange(0,Radius), Player->GetActorLocation().Y + FMath::VRand().Y * FMath::RandRange(0,Radius),Player->GetActorLocation().Z + FMath::RandRange(0,Radius));
			//Empty Array Of Actors To Ignore
			TArray<AActor*> Array;
			
			FHitResult HitResult;
			//Check Is Can Spawn Sphere
			if ( UKismetSystemLibrary::SphereTraceSingle( GetWorld(), RandPos, RandPos,  SphereClass.GetDefaultObject()->SphereMesh->GetStaticMesh()->GetBounds().GetBox().GetSize().Size(),
				ETraceTypeQuery::TraceTypeQuery1, false, Array, EDrawDebugTrace::None, HitResult, false))
			{
			}
			else
			{
				ASphereActor* SphereActor = GetWorld()->SpawnActor<ASphereActor>( SphereClass.Get(), RandPos, FRotator(0,0,0), SpawnInfo);
				SphereActor->SetActorScale3D( FVector ( CurrentSize ) );
				SphereActor->CurrentSize = CurrentSize;
				break;
			}
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
