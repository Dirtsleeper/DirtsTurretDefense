// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "SecondaryWeaponEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ESecondaryWeapon : uint8
{
	SW_FlameThrower		UMETA(DisplayName = "Flame Thrower"),
	SW_MachineGun		UMETA(DisplayName = "Machine Gun"),
	SW_GrenadeLauncher	UMETA(DisplayName = "Grenade Launcher"),
	MAX	UMETA(Hidden)
};

UCLASS()
class DIRTSTURRETDEFENSE_API USecondaryWeaponEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
