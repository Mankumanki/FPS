// Fill out your copyright notice in the Description page of Project Settings.


#include "Grass_component.h"

void UGrass_component::BeginPlay()
{
	Super::BeginPlay();
	SpawnGrass();
}

void UGrass_component::SpawnGrass()
{
	for (int i = 0; i < NumberofInstances; i++)
	{
		FVector random = FMath::RandPointInBox(AreaBox);
		AddInstance(FTransform(random));
	}
}