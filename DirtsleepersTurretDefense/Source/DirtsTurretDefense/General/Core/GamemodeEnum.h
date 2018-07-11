// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "GamemodeEnum.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EGamemode : uint8
{
	GM_Default	UMETA(DisplayName = "Default"),
	GM_Sandbox	UMETA(DisplayName = "Sandbox"),
	GM_Versus	UMETA(DisplayNAme = "Verus"),
	MAX	UMETA(Hidden)
};

UCLASS()
class DIRTSTURRETDEFENSE_API UGamemodeEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
