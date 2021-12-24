// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun_component.h"
#include "D://unreal_engine_projects//firstpersonshooter//Source//firstpersonshooter//firstpersonshooterProjectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UGun_component::UGun_component()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGun_component::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGun_component::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGun_component::Fired()
{
	if (ProjectileClass != nullptr)
	{

		FActorSpawnParameters ActorSpawnParams;
		ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		// spawn the projectile at the muzzle
		GetWorld()->SpawnActor<AfirstpersonshooterProjectile>(ProjectileClass,GetComponentLocation(),GetComponentRotation(), ActorSpawnParams);
	}

	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetComponentLocation());
	}

	// try and play a firing animation if specified
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}
