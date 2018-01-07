// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolPoints.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class S05_TRAININGARENA_API UPatrolPoints : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPatrolPoints();

	TArray<AActor*> GetPatrollPoints();

private:
	UPROPERTY(EditAnywhere, Category = "Patrol Route")
		TArray<AActor*> Waypoints;
	
};
