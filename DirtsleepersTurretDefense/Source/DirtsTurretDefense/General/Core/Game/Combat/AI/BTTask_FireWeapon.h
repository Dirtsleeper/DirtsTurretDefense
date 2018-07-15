// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TD_TaskNode.h"
#include "BTTask_FireWeapon.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UBTTask_FireWeapon : public UTD_TaskNode
{
	GENERATED_BODY()
private:

protected:

public:
	UPROPERTY(Category = Node, EditAnywhere, AdvancedDisplay)
	bool bFireOnce = false;

public:
	virtual EBTNodeResult::Type ExecuteTask(ATD_AIController* Controller, APawn* ControlledPawn) override;

	virtual EBTNodeResult::Type AbortTask(ATD_AIController* Controller, APawn* ControlledPawn) override;

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

protected:

private:
	void OnReload();
	
	
};
