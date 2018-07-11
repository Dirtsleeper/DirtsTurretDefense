// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "UpgradeTypeEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EWeaponUpgradeType : uint8
{
	UT_Damage				UMETA(DisplayName = "Damage"),
	UT_ArmorPenetration		UMETA(DisplayName = "Armor Penetration"),
	UT_FireRate				UMETA(DisplayName = "Fire Rate"),
	UT_MagazineSize			UMETA(DisplayName = "Magazine Size"),
	UT_ReloadRate			UMETA(DisplayName = "Reload Rate"),
	MAX	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ETurretUpgradeType : uint8
{
	UT_Health UMETA(DisplayName = "Health"),
	UT_Armor UMETA(DisplayName = "Armor"),
	UT_RotationSpeed UMETA(DisplayName = "RotationSpeed"),
	UT_Shield UMETA(DisplayName = "Shield"),
	UT_ShiledRegen UMETA(DisplayName = "ShieldRegen"),
	MAX UMETA(Hidden)
};

UCLASS()
class DIRTSTURRETDEFENSE_API UUpgradeTypeEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
