// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadScreenWidget.h"

#include "GenericPlatform/GenericPlatformMisc.h"
#include "GamemodeSelectionWidget.h"
#include "LoadGameWidget.h"
#include "HUD/Settings/SettingsMenuWidget.h"


void ULoadScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (_LoadSavedGameButton && !SavedGameExists())
	{
		_LoadSavedGameButton->SetIsEnabled(false);
	}
}

bool ULoadScreenWidget::BindButtons()
{
	Super::BindButtons();

	if (_StartNewGameButton)
	{
		_StartNewGameButton->OnPressed.AddDynamic(this, &ULoadScreenWidget::OnPressed_StartNewGame);
	}
	else
	{
		return false;
	}

	if (_LoadSavedGameButton)
	{
		_LoadSavedGameButton->OnPressed.AddDynamic(this, &ULoadScreenWidget::OnPressed_LoadSavedGame);
	}
	else
	{
		return false;
	}

	if (_SettingsButton)
	{
		_SettingsButton->OnPressed.AddDynamic(this, &ULoadScreenWidget::OnPressed_Settings);
	}
	else
	{
		return false;
	}

	if (_ExitGameButton)
	{
		_ExitGameButton->OnPressed.AddDynamic(this, &ULoadScreenWidget::OnPressed_ExitGame);
	}
	else
	{
		return false;
	}
	return true;
}

bool ULoadScreenWidget::SavedGameExists()
{
	return false;
}

void ULoadScreenWidget::OnPressed_StartNewGame()
{
	Close();
	m_HUD->GamemodeSelectionMenu->Open(false);
}

void ULoadScreenWidget::OnPressed_LoadSavedGame()
{
	Close();
	m_HUD->LoadGame->Open();
}

void ULoadScreenWidget::OnPressed_Settings()
{
	Close();
	m_HUD->OpenSettingsMenu(this);
}

void ULoadScreenWidget::OnPressed_ExitGame()
{
	m_PlayerController->ConsoleCommand("quit");
}
