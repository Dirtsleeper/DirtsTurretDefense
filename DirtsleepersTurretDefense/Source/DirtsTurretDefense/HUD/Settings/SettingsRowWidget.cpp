// Fill out your copyright notice in the Description page of Project Settings.

#include "SettingsRowWidget.h"

#include "Components/TextBlock.h"


void USettingsRowWidget::NativeConstruct()
{
	_SettingsMenu = Cast<ATD_HUD>(UGameplayStatics::GetPlayerController(this, 0)->GetHUD())->GetSettingsMenu();
	
	SetText(FText::FromString(EnumAsString<EGraphicSetting>(TEXT("EGraphicSetting"), _Setting, TEXT("S_"), true)));

	_Buttons.Add(_LowButton);
	_Buttons.Add(_MediumButton);
	_Buttons.Add(_HighButton);
	_Buttons.Add(_UltraButton);

	BindButtons();
}

void USettingsRowWidget::InitializeRow(EGraphicSetting Setting)
{
	_Setting = Setting;
	SetText(FText::FromString(EnumAsString<EGraphicSetting>(TEXT("EGraphicSetting"), _Setting, TEXT("S_"), true)));
}

bool USettingsRowWidget::BindButtons()
{
	Super::BindButtons();

	if (_LowButton)
	{
		_LowButton->OnPressed.AddDynamic(this, &USettingsRowWidget::OnLowPressed);
	}
	else
	{
		return false;
	}

	if (_MediumButton)
	{
		_MediumButton->OnPressed.AddDynamic(this, &USettingsRowWidget::OnMediumPressed);
	}

	if (_HighButton)
	{
		_HighButton->OnPressed.AddDynamic(this, &USettingsRowWidget::OnHighPressed);
	}
	else
	{
		return false;
	}

	if (_UltraButton)
	{
		_UltraButton->OnPressed.AddDynamic(this, &USettingsRowWidget::OnUltraPressed);
	}
	else
	{
		return false;
	}
	return true;
}

UButton* USettingsRowWidget::GetButton(EGraphicQuality Quality)
{
	switch (Quality)
	{
	case EGraphicQuality::Q_Low:
		return _LowButton;
	case EGraphicQuality::Q_Medium:
		return _MediumButton;
	case EGraphicQuality::Q_High:
		return _HighButton;
	case EGraphicQuality::Q_Ultra:
	default:
		return _UltraButton;
	}
}

void USettingsRowWidget::SetText(FText NewText)
{
	if (_SettingText)
	{
		_SettingText->SetText(NewText);
	}
}

void USettingsRowWidget::EnableButtons(UButton* DisabledButton)
{
	for (UButton* Button : _Buttons)
	{
		Button->SetIsEnabled(Button != DisabledButton);
	}
}

void USettingsRowWidget::OnLowPressed()
{
	_SettingsMenu->ApplySetting(_Setting, EGraphicQuality::Q_Low);
}

void USettingsRowWidget::OnMediumPressed()
{
	_SettingsMenu->ApplySetting(_Setting, EGraphicQuality::Q_Medium);
}

void USettingsRowWidget::OnHighPressed()
{
	_SettingsMenu->ApplySetting(_Setting, EGraphicQuality::Q_High);
}

void USettingsRowWidget::OnUltraPressed()
{
	_SettingsMenu->ApplySetting(_Setting, EGraphicQuality::Q_Ultra);
}
