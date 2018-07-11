// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "PrimaryWeaponEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EPrimaryWeapon : uint8
{
	PW_Canon			UMETA(DisplayName = "Canon"),
	PW_ElectricCanon	UMETA(DisplayName = "Electric Cancon"),
	PW_Rockets			UMETA(DisplayName = "Rockets"),
	MAX	UMETA(Hidden)
};

UCLASS()
class DIRTSTURRETDEFENSE_API UPrimaryWeaponEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
