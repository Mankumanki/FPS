// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "D://unreal_engine_projects//firstpersonshooter/Source/firstpersonshooter/firstpersonshooterGameMode.h"
#include "Infinte_level_Gamemode.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSONSHOOTER_API AInfinte_level_Gamemode : public AfirstpersonshooterGameMode
{
	GENERATED_BODY()

public:
	AInfinte_level_Gamemode();

	UFUNCTION(BlueprintCallable, Category = "Pooling")
	void PoolNavMesh();

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Pooling")
	class UActorPool* Pool;

private:

	void AddToPool(class ANavMeshBoundsVolume* Navmesh);

};
