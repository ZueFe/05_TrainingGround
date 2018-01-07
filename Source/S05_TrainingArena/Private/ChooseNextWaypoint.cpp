// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolPoints.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	//TODO: protect against empty patrol route

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	//Get the patrol points
	auto PatrolRouteComp = OwnerComp.GetAIOwner()->GetPawn()->FindComponentByClass<UPatrolPoints>();

	if (!ensure(PatrolRouteComp)) { return EBTNodeResult::Failed; }

	auto WaypointsCPP = PatrolRouteComp->GetPatrollPoints();
	if (WaypointsCPP.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard has no patrol points"));
		return EBTNodeResult::Failed;
	}
	

	//Set waypoint
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, WaypointsCPP[Index]);

	//Cycle index
	Index = (Index + 1) % WaypointsCPP.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	return EBTNodeResult::Succeeded;
}

