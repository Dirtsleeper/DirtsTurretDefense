// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/UserDefinedEnum.h"
#include "GraphicSettingEnum.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EGraphicSetting : uint8
{
	S_Quality			UMETA(DisplayName = "Quality"),
	S_ResolutionScale	UMETA(DisplayName = "Resolution Scale"),
	S_ViewDistance		UMETA(DisplayName = "View Distance"),
	S_AntiAliasing		UMETA(DisplayName = "Anti-Aliasing"),
	S_PostProcessing	UMETA(DisplayName = "Post Processing"),
	S_Shadows			UMETA(DisplayName = "Shadows"),
	S_Textures			UMETA(DisplayName = "Textures"),
	S_Effects			UMETA(DisplayName = "Effects"),
	S_Foliage			UMETA(DisplayName = "Foliage"),
	MAX	UMETA(Hidden)
};

UCLASS()
class DIRTSTURRETDEFENSE_API UGraphicSettingEnum : public UUserDefinedEnum
{
	GENERATED_BODY()
	
	
	
	
};
