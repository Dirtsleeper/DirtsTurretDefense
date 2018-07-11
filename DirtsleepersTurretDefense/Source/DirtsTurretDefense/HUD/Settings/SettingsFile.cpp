// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsFile.h"

#include "SettingsMenuWidget.h"
#include "GraphicSettingEnum.h"


void USettingsFile::Save()
{
	UGameplayStatics::SaveGameToSlot(this, TEXT("GraphicSettings"), 0);
}

void USettingsFile::SaveSetting(EGraphicSetting Setting, EGraphicQuality Quality)
{
	if (_Settings.Contains(Setting))
	{
		_Settings[Setting] = Quality;
	}
	else
	{
		_Settings.Add(Setting, Quality);
	}
	Save();
}

void USettingsFile::LoadSettings(class USettingsMenuWidget* SettingsMenu)
{
	for (auto It = _Settings.CreateIterator(); It; ++It)
	{
		SettingsMenu->ApplySetting(It.Key(), It.Value());
	}
}
