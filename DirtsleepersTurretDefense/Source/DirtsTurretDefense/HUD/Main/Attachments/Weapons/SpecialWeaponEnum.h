// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "SpecialWeaponEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ESpecialWeapon : uint8
{
	SW_AC_130	UMETA(DisplayName = "AC-130"),
	SW_AirStrike	UMETA(DisplayName = "Air Strike"),
	SW_DeployableDrone	UMETA(DisplayName = "Deployable Drone"),
	SW_ControllableOrdinance	UMETA(DisplayName = "Controllable Ordinance"),
	MAX	UMETA(Hidden)

};

UCLASS()
class DIRTSTURRETDEFENSE_API USpecialWeaponEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
