// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TD_AIController.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "General/Core/Game/Combat/CombatInterface.h"
#include "Player/Weapons/WeaponInterface.h"

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "TD_TaskNode.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UTD_TaskNode : public UBTTaskNode
{
	GENERATED_BODY()
private:

protected:

public:

public:
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	virtual EBTNodeResult::Type AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual EBTNodeResult::Type ExecuteTask(ATD_AIController* Controller, APawn* ControlledPawn);

	virtual EBTNodeResult::Type AbortTask(ATD_AIController* Controller, APawn* ControlledPawn);

private:
	
	
	
};
