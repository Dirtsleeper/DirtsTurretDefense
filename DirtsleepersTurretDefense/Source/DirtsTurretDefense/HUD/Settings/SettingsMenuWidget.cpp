// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsMenuWidget.h"

#include "SettingsRowWidget.h"
#include "SettingsFile.h"


void USettingsMenuWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (_Quality)
	{
		_Quality->InitializeRow(EGraphicSetting::S_Quality);
	}

	if (_ResolutionScale)
	{
		_ResolutionScale->InitializeRow(EGraphicSetting::S_ResolutionScale);
	}

	if (_ViewDistance)
	{
		_ViewDistance->InitializeRow(EGraphicSetting::S_ViewDistance);
	}

	if (_AntiAliasing)
	{
		_AntiAliasing->InitializeRow(EGraphicSetting::S_AntiAliasing);
	}

	if (_PostProcessing)
	{
		_PostProcessing->InitializeRow(EGraphicSetting::S_PostProcessing);
	}

	if (_Shadows)
	{
		_Shadows->InitializeRow(EGraphicSetting::S_Shadows);
	}

	if (_Textures)
	{
		_Textures->InitializeRow(EGraphicSetting::S_Textures);
	}

	if (_Effects)
	{
		_Effects->InitializeRow(EGraphicSetting::S_Effects);
	}

	if (_Foliage)
	{
		_Foliage->InitializeRow(EGraphicSetting::S_Foliage);
	}
}

void USettingsMenuWidget::NativeConstruct()
{
	if (UGameplayStatics::DoesSaveGameExist(TEXT("GraphicSettings"), 0))
	{
		_SettingsFile = Cast<USettingsFile>(UGameplayStatics::LoadGameFromSlot(TEXT("GraphicSettings"), 0));
		_SettingsFile->LoadSettings(this);
		UE_LOG(LogTemp, Log, TEXT("Settings File Loaded."));
	}
	else
	{
		_SettingsFile = Cast<USettingsFile>(UGameplayStatics::CreateSaveGameObject(USettingsFile::StaticClass()));
		UE_LOG(LogTemp, Log, TEXT("Settings File Created."));
	}

	BindButtons();
}

void USettingsMenuWidget::ApplySetting(EGraphicSetting Setting, EGraphicQuality Quality, bool bSave)
{
	FString Command;
	float Value = 0;

	if (Setting != EGraphicSetting::S_ResolutionScale)
	{
		switch (Quality)
		{
		case EGraphicQuality::Q_Low:
			Value = 0.f;
			break;
		case EGraphicQuality::Q_Medium:
			Value = 1.f;
			break;
		case EGraphicQuality::Q_High:
			Value = 2.f;
			break;
		case EGraphicQuality::Q_Ultra:
			Value = 3.f;
			break;
		}
	}

	if (Setting == EGraphicSetting::S_Quality)
	{
		_Quality->EnableButtons(_Quality->GetButton(Quality));
		for (EGraphicSetting GS : EnumGetList<EGraphicSetting>(TEXT("EGraphicSetting")))
		{
			if (GS == EGraphicSetting::S_Quality)
			{
				continue;
			}
			ApplySetting(GS, Quality, false);
		}
	}
	else
	{
		switch (Setting)
		{
		case EGraphicSetting::S_ResolutionScale:
			_ResolutionScale->EnableButtons(_ResolutionScale->GetButton(Quality));
			Command = TEXT("r.ScreenPercentage");
			switch (Quality)
			{
			case EGraphicQuality::Q_Low:
				Value = 60.f;
				break;
			case EGraphicQuality::Q_Medium:
				Value = 80.f;
				break;
			case EGraphicQuality::Q_High:
			case EGraphicQuality::Q_Ultra:
				Value = 100.f;
				break;
			}
			break;
		case EGraphicSetting::S_ViewDistance:
			_ViewDistance->EnableButtons(_ViewDistance->GetButton(Quality));
			Command = TEXT("r.ViewDistanceScale");
			Value /= 4 + 0.25f;
			break;
		case EGraphicSetting::S_AntiAliasing:
			_AntiAliasing->EnableButtons(_AntiAliasing->GetButton(Quality));
			Command = TEXT("r.PostProcessAAQuality");
			Value *= 2.f;
			break;
		case EGraphicSetting::S_PostProcessing:
			_PostProcessing->EnableButtons(_PostProcessing->GetButton(Quality));
			Command = TEXT("sg.PostProcessQuality");
			break;
		case EGraphicSetting::S_Shadows:
			_Shadows->EnableButtons(_Shadows->GetButton(Quality));
			Command = TEXT("sg.ShadowQuality");
			break;
		case EGraphicSetting::S_Textures:
			_Textures->EnableButtons(_Textures->GetButton(Quality));
			Command = TEXT("sg.TextureQuality");
			break;
		case EGraphicSetting::S_Effects:
			_Effects->EnableButtons(_Effects->GetButton(Quality));
			Command = TEXT("sg.EffectsQuality");
			break;
		case EGraphicSetting::S_Foliage:
			_Foliage->EnableButtons(_Foliage->GetButton(Quality));
			Command = TEXT("sg.FoliageQuality");
			break;
		}
	}

	if (bSave)
	{
		_SettingsFile->SaveSetting(Setting, Quality);
	}
	if (Setting != EGraphicSetting::S_Quality)
	{
		UGameplayStatics::GetPlayerController(this, 0)->ConsoleCommand(Command + TEXT(" ") + FString::SanitizeFloat(Value), _bLogConsoleCommands);
	}
}

void USettingsMenuWidget::SetReturnWidget(UTD_Widget* ReturnWidget)
{
	_ReturnWidget = ReturnWidget;
}

bool USettingsMenuWidget::BindButtons()
{
	Super::BindButtons();

	if (_BackButton)
	{
		_BackButton->OnPressed.AddDynamic(this, &USettingsMenuWidget::OnBackButtonPressed);
	}
	else
	{
		return false;
	}
	return true;
}

void USettingsMenuWidget::OnBackButtonPressed()
{
	Close(false);
	_ReturnWidget->Open(false);
}
