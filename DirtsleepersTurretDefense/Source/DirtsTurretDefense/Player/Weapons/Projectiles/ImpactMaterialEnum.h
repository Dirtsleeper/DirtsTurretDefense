// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "ImpactMaterialEnum.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EImpactMaterial : uint8
{
	Terrain,
	Body,
	Metal,
	MAX UMETA(Hidden)
};

UCLASS()
class DIRTSTURRETDEFENSE_API UImpactMaterialEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
