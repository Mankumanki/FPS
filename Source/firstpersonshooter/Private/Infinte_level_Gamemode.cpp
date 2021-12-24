// Fill out your copyright notice in the Description page of Project Settings.


#include "Infinte_level_Gamemode.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfinte_level_Gamemode::AInfinte_level_Gamemode()
{
	Pool=CreateDefaultSubobject<UActorPool>(FName("Pooling_component"));
}

void AInfinte_level_Gamemode::PoolNavMesh()
{
	auto Navmeshes=TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (Navmeshes)
	{
		AddToPool(*Navmeshes);
		++Navmeshes;
	}
}

void AInfinte_level_Gamemode::AddToPool(ANavMeshBoundsVolume* Navmesh)
{
	Pool->Add(Navmesh);
}
