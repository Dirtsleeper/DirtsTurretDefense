// Fill out your copyright notice in the Description page of Project Settings.

#include "GameWidget.h"

#include "General/Core/Game/GameplayUtilLibrary.h"

UGameWidget::UGameWidget()
{
	m_bRequiresFadeAnimation = true;
}

void UGameWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameMode = UGameUtilLibrary::GetGameMode(this);
	PlayerController = UGameUtilLibrary::GetPlayerController(this);
	HUD = UGameUtilLibrary::GetHUD(PlayerController);
}
