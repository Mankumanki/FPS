// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ground_tile.generated.h"

UCLASS()
class FIRSTPERSONSHOOTER_API AGround_tile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGround_tile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Navigation_Offset")
		FVector NavOffset;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Objects")
	TArray<AActor*> SpawnObject(TSubclassOf<AActor>Object, int high, int low, float Radius,float min_scale,float max_scale);

	UFUNCTION(BlueprintCallable, Category = "NPC")
	TArray<APawn*> SpawnAI(TSubclassOf<APawn>Object, int high, int low, float Radius);

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(class UActorPool* ToPool);

	TArray<AActor*> objectspawned;
	TArray<APawn*> AI;

private: 
	bool CastSphere(FVector Location, float Radius);
	bool FindEmptyLocation(FVector& OutLocation, float Radius);
	AActor* PlaceActor(TSubclassOf<AActor>Object, FVector SpawnPoint,float Rotation,float Scale);
	APawn* PlaceAI(TSubclassOf<APawn>Object, FVector SpawnPoint, float Rotation);
	void PositionNavMesh();
	class UActorPool* Pool;
	AActor* NavMesh;
};
