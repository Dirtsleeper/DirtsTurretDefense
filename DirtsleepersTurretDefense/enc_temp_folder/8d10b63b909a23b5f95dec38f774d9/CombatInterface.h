// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "General/Core/Game/Combat/AI/TD_AIController.h"
#include "Combat/DamageInfoStruct.h"

#include "CoreMinimal.h"
#include "General/Core/ActorInterface.h"
#include "CombatInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCombatInterface : public UActorInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DIRTSTURRETDEFENSE_API ICombatInterface : public IActorInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FText GetEnemyName() = 0;

	virtual class UCombatComponent* GetCombatComponent();

	virtual bool HasShieldComponent();

	virtual class UShieldComponent* GetShieldComponent();

	virtual void TakeDamage(const FDamageInfo& DamageInfo);

	virtual struct FCombatInfo* GetCombatInfo();

	virtual void OnDeath(AActor* Source);

protected:
	virtual void OnBeginPlay();

	virtual void InitializeAIController(TSubclassOf<ATD_AIController> ControllerClass = ATD_AIController::StaticClass());

	virtual void OnPossessed(AController* NewController);

};
