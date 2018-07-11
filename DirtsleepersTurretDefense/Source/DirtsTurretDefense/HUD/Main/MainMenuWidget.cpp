// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuWidget.h"

bool UMainMenuWidget::BindButtons()
{
	Super::BindButtons();

	if (_StartMissionButton)
	{
		_StartMissionButton->OnPressed.AddDynamic(this, &UMainMenuWidget::OnPressed_StartMissionButton);
	}
	else
	{
		return false;
	}

	if (_MainMenuButton)
	{
		_MainMenuButton->OnPressed.AddDynamic(this, &UMainMenuWidget::OnPressed_MainMenuButton);
	}
	else
	{
		return false;
	}
	return true;
}

void UMainMenuWidget::OnPressed_StartMissionButton()
{

}

void UMainMenuWidget::OnPressed_MainMenuButton()
{
	UGameplayStatics::OpenLevel(this, TEXT("LoadScreen"));
}
