// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_TaskNode.h"




EBTNodeResult::Type UTD_TaskNode::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ATD_AIController* Controller = Cast<ATD_AIController>(OwnerComp.GetAIOwner()))
	{
		if (APawn* Pawn = Cast<APawn>(Controller->GetPawn()))
		{
			return AbortTask(Controller, Pawn);
		}
	}
	UE_LOG(LogTemp, Error, TEXT("TD_TaskNode::AbortTask failed to create Controller and Pawn."));
	return EBTNodeResult::Failed;
}

EBTNodeResult::Type UTD_TaskNode::AbortTask(ATD_AIController* Controller, APawn* ControlledPawn)
{
	return EBTNodeResult::Succeeded;
}

EBTNodeResult::Type UTD_TaskNode::ExecuteTask(ATD_AIController* Controller, APawn* ControlledPawn)
{
	return EBTNodeResult::Succeeded;
}

EBTNodeResult::Type UTD_TaskNode::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (ATD_AIController* Controller = Cast<ATD_AIController>(OwnerComp.GetAIOwner()))
	{
		if (APawn* Pawn = Cast<APawn>(Controller->GetPawn()))
		{
			return ExecuteTask(Controller, Pawn);
		}
	}
	UE_LOG(LogTemp, Error, TEXT("TD_TaskNode::ExecuteTask failed to create Controller and Pawn."));
	return EBTNodeResult::Failed;
}
