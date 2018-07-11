// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "GraphicQualityEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EGraphicQuality : uint8
{
	Q_Low		UMETA(DisplayName = "Low"),
	Q_Medium	UMETA(DisplayName = "Medium"),
	Q_High		UMETA(DisplayName = "High"),
	Q_Ultra		UMETA(DisplayName = "Ultra"),
	MAX	UMETA(Hidden)
};

UCLASS()
class DIRTSTURRETDEFENSE_API UGraphicQualityEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
