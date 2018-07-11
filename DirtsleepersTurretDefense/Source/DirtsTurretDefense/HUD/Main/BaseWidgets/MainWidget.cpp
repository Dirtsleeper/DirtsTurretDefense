// Fill out your copyright notice in the Description page of Project Settings.

#include "MainWidget.h"

#include "General/Core/MainMenu/MainMenuUtilLibrary.h"


UMainWidget::UMainWidget()
{
	m_bRequiresFadeAnimation = true;
}

void UMainWidget::NativeConstruct()
{
	Super::NativeConstruct();

	m_GameMode = UMainMenuUtilLibrary::GetGameMode(this);
	m_PlayerController = UMainMenuUtilLibrary::GetPlayerController(this);
	m_HUD = UMainMenuUtilLibrary::GetHUD(m_PlayerController);
}
