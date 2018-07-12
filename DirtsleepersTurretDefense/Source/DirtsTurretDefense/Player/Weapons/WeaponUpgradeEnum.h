// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "WeaponUpgradeEnum.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EWeaponUpgrade : uint8
{
	WU_Damage				UMETA(DisplayName = "Damage"),
	WU_ArmorPenetration		UMETA(DisplayName = "Armor Penetration"),
	WU_FireRate				UMETA(DisplayName = "Fire Rate"),
	WU_MagazineSize			UMETA(DisplayName = "Magazine Size"),
	WU_ReloadTime			UMETA(DisplayName = "Reload Time"),
	MAX	UMETA(Hidden)

};

UCLASS()
class DIRTSTURRETDEFENSE_API UWeaponUpgradeEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
