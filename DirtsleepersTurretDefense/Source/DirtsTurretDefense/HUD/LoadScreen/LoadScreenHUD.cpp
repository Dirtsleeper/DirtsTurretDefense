// Fill out your copyright notice in the Description page of Project Settings.

#include "LoadScreenHUD.h"

#include "LoadScreenWidget.h"
#include "LoadGameWidget.h"
#include "GamemodeSelectionWidget.h"


void ALoadScreenHUD::BeginPlay()
{
	Super::BeginPlay();

	LoadScreen->Open(true);
}

void ALoadScreenHUD::CreateWidgets()
{
	Super::CreateWidgets();

	LoadScreen = CreateWidget<ULoadScreenWidget>(GetWorld(), LoadScreenClass);
	if (LoadScreen)
	{
		LoadScreen->AddToViewport();
		LoadScreen->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to Create LoadScreenWidget"));
	}

	LoadGame = CreateWidget<ULoadGameWidget>(GetWorld(), LoadGameClass);
	if (LoadGame)
	{
		LoadGame->AddToViewport();
		LoadGame->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to Create LoadGameWidget"));
	}

	GamemodeSelectionMenu = CreateWidget<UGamemodeSelectionWidget>(GetWorld(), GamemodeSelectionMenuClass);
	if (GamemodeSelectionMenu)
	{
		GamemodeSelectionMenu->AddToViewport();
		GamemodeSelectionMenu->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to Create GamemodeSelectionMenu"));
	}
}
