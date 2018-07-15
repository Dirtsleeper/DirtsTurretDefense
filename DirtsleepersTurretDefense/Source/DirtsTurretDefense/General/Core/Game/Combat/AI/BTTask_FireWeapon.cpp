// Fill out your copyright notice in the Description page of Project Settings.

#include "BTTask_FireWeapon.h"



EBTNodeResult::Type UBTTask_FireWeapon::ExecuteTask(ATD_AIController* Controller, APawn* ControlledPawn)
{
	IWeaponInterface* Interface = Cast<IWeaponInterface>(ControlledPawn);
	if (bFireOnce)
	{
		Interface->FirePressed();
		Interface->FireReleased();
		return EBTNodeResult::Succeeded;
	}
	else
	{
		return EBTNodeResult::InProgress;
	}
}

EBTNodeResult::Type UBTTask_FireWeapon::AbortTask(ATD_AIController* Controller, APawn* ControlledPawn)
{
	IWeaponInterface* Interface = Cast<IWeaponInterface>(ControlledPawn);
	Interface->FireReleased();
	return EBTNodeResult::Succeeded;
}

void UBTTask_FireWeapon::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	IWeaponInterface* Interface = Cast<IWeaponInterface>(OwnerComp.GetAIOwner()->GetPawn());
	if (!Interface->GetSelectedWeapon()->IsFiring())
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
