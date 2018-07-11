// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadWidget.h"

#include "General/Core/MainMenu/MainMenuUtilLibrary.h"


ULoadWidget::ULoadWidget()
{
	m_bRequiresFadeAnimation = true;
}

void ULoadWidget::NativeConstruct()
{
	Super::NativeConstruct();

	m_GameMode = Cast<ALoadScreenGameMode>(UGameplayStatics::GetGameMode(this));
	m_PlayerController = Cast<ALoadScreenPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	m_HUD = Cast<ALoadScreenHUD>(m_PlayerController->GetHUD());
}
