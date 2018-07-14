// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "WeaponTypeEnum.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	Primary,
	Secondary,
	Special,
	MAX UMETA(Hidden)
};

UCLASS()
class DIRTSTURRETDEFENSE_API UWeaponTypeEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
