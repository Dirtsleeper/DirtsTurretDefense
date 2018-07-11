// Fill out your copyright notice in the Description page of Project Settings.

#include "MainHUD.h"

#include "MainMenuWidget.h"

void AMainHUD::BeginPlay()
{
	Super::BeginPlay();

	MainMenu->Open(true);
}

void AMainHUD::CreateWidgets()
{
	Super::CreateWidgets();

	MainMenu = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuClass);
	if (MainMenu)
	{
		MainMenu->AddToViewport();
		MainMenu->SetVisibility(ESlateVisibility::Collapsed);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to Create MainMenuWidget"));
	}
}
