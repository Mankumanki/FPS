// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPool.h"

// Sets default values for this component's properties
UActorPool::UActorPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor* UActorPool::Checkout()
{
	if (PoolofObjects.Num() == 0)
	{
		return nullptr;
	}
	else
	{
	  AActor* NavMesh = PoolofObjects.Pop();
	  return NavMesh;
	}
}

void UActorPool::ReturnActor(AActor* ActortoReturn)
{
	if (ActortoReturn == nullptr)
	{
		return;
	}
	else
	{
		Add(ActortoReturn);
		UE_LOG(LogTemp, Warning, TEXT("Object returned to pool:%s"), *ActortoReturn->GetName());
	}
}

void UActorPool::Add(AActor* ActorToAdd)
{
	if (ActorToAdd == nullptr)
	{
		return;
	}
	else
	{
		PoolofObjects.Push(ActorToAdd);
		UE_LOG(LogTemp, Warning, TEXT("Object added to pool:%s"), *ActorToAdd->GetName());
	}
}

