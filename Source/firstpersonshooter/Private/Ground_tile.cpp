// Fill out your copyright notice in the Description page of Project Settings.


#include "Ground_tile.h"
#include "EngineUtils.h"
#include "ActorPool.h"

// Sets default values
AGround_tile::AGround_tile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NavOffset = FVector(2000.0f, 0.0f, 0.0f);
}

void AGround_tile::SetPool(class UActorPool* ToPool)
{
	Pool = ToPool;
	PositionNavMesh();
}

void AGround_tile::PositionNavMesh()
{
	NavMesh = Pool->Checkout();
	if (NavMesh == nullptr)
	{
		return;
	}
		NavMesh->SetActorLocation(GetActorLocation()+NavOffset);
		FNavigationSystem::Build(*GetWorld());
}

// Called when the game starts or when spawned
void AGround_tile::BeginPlay()
{
	Super::BeginPlay();
}

void AGround_tile::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Pool->ReturnActor(NavMesh);
}
// Called every frame
void AGround_tile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


TArray<AActor*> AGround_tile::SpawnObject(TSubclassOf<AActor>Object,int high,int low,float Radius, float min_scale, float max_scale)
{
	int rand_size = FMath::RandRange(low, high);
	for (int i = 0; i < rand_size; i++)
	{
		FVector SpawnPoint;
		float Scale = FMath::RandRange(min_scale, max_scale);
		if (FindEmptyLocation(SpawnPoint, Radius*Scale))
		{
			float Rotation = FMath::RandRange(-180.0f,180.0f);
			objectspawned.Push(PlaceActor(Object, SpawnPoint,Rotation,Scale));
		}
	}
	return objectspawned;
}

bool AGround_tile::FindEmptyLocation(FVector&OutLocation,float Radius)
{
	FVector min = FVector(0, -2000, 0);
	FVector max = FVector(4000,2000, 0);	
	int max_size = 40;
	for (int k = 0; k <= max_size; k++)
	{
		FVector Candidate = FMath::RandPointInBox(FBox(min, max));
		if (CastSphere(Candidate, Radius))
		{
			OutLocation = Candidate;
			return true;
		}
	
	}
	return false;
}

AActor* AGround_tile::PlaceActor(TSubclassOf<AActor>Object,FVector SpawnPoint, float Rotation,float Scale)
{
	if (Object == NULL)
	{
		return nullptr;
	}
	AActor* mesh_object = GetWorld()->SpawnActor(Object);
	mesh_object->SetActorRelativeLocation(SpawnPoint);
	mesh_object->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	mesh_object->SetActorRotation(FRotator(0.0f, Rotation, 0.0f));
	mesh_object->SetActorRelativeScale3D(FVector(Scale, Scale, Scale));
	
	return mesh_object;
}

bool AGround_tile::CastSphere(FVector Location, float Radius)
{
	FHitResult Hit;
	FVector GlobalPosition = ActorToWorld().TransformPosition(Location);

	bool IfHit = GetWorld()->SweepSingleByChannel(Hit, GlobalPosition, GlobalPosition,FQuat::Identity,ECollisionChannel::ECC_GameTraceChannel2,FCollisionShape::MakeSphere(Radius));

	return !IfHit;
}

TArray<APawn*> AGround_tile::SpawnAI(TSubclassOf<APawn>Object, int high, int low, float Radius)
{
	int rand_size = FMath::RandRange(low, high);
	for (int i = 0; i < rand_size; i++)
	{
		FVector SpawnPoint;
		if (FindEmptyLocation(SpawnPoint, Radius))
		{
			float Rotation = FMath::RandRange(-180.0f, 180.0f);
			AI.Push(PlaceAI(Object, SpawnPoint, Rotation));
		}
	}

	return AI;
}

APawn* AGround_tile::PlaceAI(TSubclassOf<APawn>Object, FVector SpawnPoint, float Rotation)
{
	if (Object == NULL)
	{
		return nullptr;
	}
	auto mesh_object = GetWorld()->SpawnActor<APawn>(Object);
	mesh_object->SetActorRelativeLocation(SpawnPoint);
	mesh_object->AttachToActor(this, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
	mesh_object->SetActorRotation(FRotator(0.0f, Rotation, 0.0f));
	mesh_object->SpawnDefaultController();
	mesh_object->Tags.Add(FName("NPC"));

	return mesh_object;
}