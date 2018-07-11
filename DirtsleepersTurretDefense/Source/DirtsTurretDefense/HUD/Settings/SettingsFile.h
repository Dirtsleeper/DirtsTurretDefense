// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SettingsFile.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API USettingsFile : public USaveGame
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TMap<EGraphicSetting, EGraphicQuality> _Settings;

protected:

public:

public:
	void Save();

	void SaveSetting(EGraphicSetting Setting, EGraphicQuality Quality);

	void LoadSettings(class USettingsMenuWidget* SettingsMenu);

protected:

private:
	
	
	
};
