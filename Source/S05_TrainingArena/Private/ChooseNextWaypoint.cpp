// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrollingGuard.h"
#include "AIController.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {

	//TODO: protect against empty patrol route

	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);

	//Get the patrol points
	auto Controller = Cast<APatrollingGuard>(OwnerComp.GetAIOwner()->GetPawn());
	auto WaypointsCPP = Controller->WaypointsCPP;

	//Set waypoint
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, WaypointsCPP[Index]);

	//Cycle index
	Index = (Index + 1) % WaypointsCPP.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, Index);

	return EBTNodeResult::Succeeded;
}

