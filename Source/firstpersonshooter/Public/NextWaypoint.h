// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "NextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPERSONSHOOTER_API UNextWaypoint : public UBTTaskNode
{
	GENERATED_BODY()
	
public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UBlackboardComponent* blackboard;
	UPROPERTY(EditAnywhere,Category="Balckboard Keys")
	struct FBlackboardKeySelector IndexKey;
	UPROPERTY(EditAnywhere, Category = "Balckboard Keys")
	struct FBlackboardKeySelector WaypointsKey;
	TArray<AActor*>Points;
	float index=0;
};
