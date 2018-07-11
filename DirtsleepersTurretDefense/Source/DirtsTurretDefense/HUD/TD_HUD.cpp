// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_HUD.h"

#include "Settings/SettingsMenuWidget.h"

void ATD_HUD::OpenSettingsMenu(UTD_Widget* ReturnWidget)
{
	if (ReturnWidget)
	{
		_SettingsMenu->Open(false);
		_SettingsMenu->SetReturnWidget(ReturnWidget);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid ReturnWidget passed to ATD_HUD::OpenSettingsMenu"));
	}
}

USettingsMenuWidget* ATD_HUD::GetSettingsMenu()
{
	return _SettingsMenu;
}

void ATD_HUD::BeginPlay()
{
	Super::BeginPlay();

	CreateWidgets();
}

void ATD_HUD::CreateWidgets()
{
	_SettingsMenu = CreateWidget<USettingsMenuWidget>(GetWorld(), SettingsMenuClass);
	if (_SettingsMenu)
	{
		_SettingsMenu->AddToViewport();
		_SettingsMenu->SetVisibility(ESlateVisibility::Collapsed);
	}
}
