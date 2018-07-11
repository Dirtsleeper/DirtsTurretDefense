// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "TurretAttachmentEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ETurretAttachment : uint8
{
	TA_HealthUpgrade	UMETA(DisplayName = "Health Upgrade"),
	TA_Armor			UMETA(DisplayName = "Armor"),
	TA_GearBox			UMETA(DisplayName = "Gear Box"),
	TA_Shield			UMETA(DisplayName = "Shield"),
	TA_ShildRegenerator	UMETA(DisplayName = "ShieldRegenerator"),
	MAX	UMETA(Hidden)
};

UCLASS()
class DIRTSTURRETDEFENSE_API UTurretAttachmentEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
