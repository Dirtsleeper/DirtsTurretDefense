// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "CombatInfoStruct.generated.h"

/**
 * 
 */

class UBehaviorTree;

USTRUCT(BlueprintType)
struct FCombatInfo : public FTableRowBase
{
	GENERATED_BODY()
private:

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Health = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Armor = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Shield = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ShieldRegen = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 WeaponID = -1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBehaviorTree* BehaviorTree;

public:

public:
	float GetHealth();

	float GetArmor();

	float GetShield();

	float GetShieldRegen();

	int32 GetWeaponID();

	UBehaviorTree* GetBehaviorTree();

protected:

private:

};

UCLASS()
class DIRTSTURRETDEFENSE_API UCombatInfoStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
	
	
	
	
};
