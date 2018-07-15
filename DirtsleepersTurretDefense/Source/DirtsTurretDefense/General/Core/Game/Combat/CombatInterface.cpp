// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatInterface.h"
#include "General/Core/TurretDefenseGameInstance.h"

#include "CombatComponent.h"
#include "General/Core/Game/Combat/AI/TD_AIController.h"
#include "General/Core/Game/Combat/CombatInfoStruct.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Combat/ShieldComponent.h"


// Add default functionality here for any ICombatInterface functions that are not pure virtual.

UCombatComponent* ICombatInterface::GetCombatComponent()
{
	UCombatComponent* Comp = Cast<UCombatComponent>(GetOwner()->GetComponentByClass(UCombatComponent::StaticClass()));
	check(Comp != nullptr);
	return Comp;
}

bool ICombatInterface::HasShieldComponent()
{
	return Cast<UShieldComponent>(GetOwner()->GetComponentByClass(UShieldComponent::StaticClass())) != nullptr;
}

class UShieldComponent* ICombatInterface::GetShieldComponent()
{
	return Cast<UShieldComponent>(GetOwner()->GetComponentByClass(UShieldComponent::StaticClass()));
}

void ICombatInterface::TakeDamage(const FDamageInfo& DamageInfo)
{
	GetCombatComponent()->TakeDamage(DamageInfo);
}

struct FCombatInfo* ICombatInterface::GetCombatInfo()
{
	return GI::GetGameInstance(GetOwner())->GetCombatInfoFromDataTable(GetOwner());
}

void ICombatInterface::OnBeginPlay()
{
	FTimerHandle th;
	FTimerDelegate Delegate;
	Delegate.BindLambda([this]
	{
		InitializeAIController();
	});
	GetOwner()->GetWorld()->GetTimerManager().SetTimer(th, Delegate, 1.0f, false);
}

void ICombatInterface::InitializeAIController(TSubclassOf<ATD_AIController> ControllerClass /*= ATD_AIController::StaticClass()*/)
{
	ATD_AIController* Controller = GetOwner()->GetWorld()->SpawnActor<ATD_AIController>(ControllerClass);
	Controller->Possess(Cast<APawn>(this));
}

void ICombatInterface::OnPossessed(AController* NewController)
{
	ATD_AIController* AIController = Cast<ATD_AIController>(NewController);
	UBlackboardComponent* BBComp;
	UBehaviorTree* BehaviorTree = GetCombatInfo()->GetBehaviorTree();
	UBlackboardData* Blackboard = BehaviorTree->BlackboardAsset;
	AIController->UseBlackboard(Blackboard, BBComp);
	BBComp->SetValueAsObject(FName(*FString(TEXT("Target"))), UGameplayStatics::GetPlayerPawn(GetOwner(), 0));
	AIController->RunBehaviorTree(BehaviorTree);
}

void ICombatInterface::OnDeath(AActor* Source)
{

}
