// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Grass_component.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom),meta=(BlueprintSpawnableComponent))
class FIRSTPERSONSHOOTER_API UGrass_component : public UHierarchicalInstancedStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly, Category = "Grass_Spawn")
		FBox AreaBox;

	UPROPERTY(EditDefaultsOnly, Category = "Grass_Spawn")
		int NumberofInstances;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SpawnGrass();
};
