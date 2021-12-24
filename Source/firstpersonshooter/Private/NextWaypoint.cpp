// Fill out your copyright notice in the Description page of Project Settings.


#include "NextWaypoint.h"
#include "AIController.h"
#include "PatrolRouteComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	blackboard = OwnerComp.GetBlackboardComponent();
	auto Index = blackboard->GetValueAsInt(IndexKey.SelectedKeyName);

	//GetPatrolPoints
	auto OwnerControl = OwnerComp.GetAIOwner();
	auto Pawn = OwnerControl->GetPawn();
	auto patrolguard = Pawn->FindComponentByClass<UPatrolRouteComponent>();

	if (!ensure(patrolguard))
	{
		return(EBTNodeResult::Failed);
	}
	 Points = patrolguard->GetPoints();

	if (Points.Num() == 0)
	{
		return(EBTNodeResult::Failed);
	}
	//SetWaypoint
	auto Pointlength = Points.Num();
	blackboard->SetValueAsObject(WaypointsKey.SelectedKeyName, Points[Index]);
	Index = Index + 1;
	blackboard->SetValueAsInt(IndexKey.SelectedKeyName,(Index%Pointlength));

	UE_LOG(LogTemp, Warning, TEXT("Working,Index is:%d"),Index);
	return (EBTNodeResult::Succeeded);
}
