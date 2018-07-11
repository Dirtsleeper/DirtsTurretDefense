// Fill out your copyright notice in the Description page of Project Settings.

#include "GamemodeSelectionWidget.h"

#include "General/Core/TurretDefenseGameInstance.h"


bool UGamemodeSelectionWidget::BindButtons()
{
	Super::BindButtons();

	if (_DefaultButton)
	{
		_DefaultButton->OnPressed.AddDynamic(this, &UGamemodeSelectionWidget::OnPressed_Default);
	}
	else
	{
		return false;
	}

	if (_SandboxButton)
	{
		_SandboxButton->OnPressed.AddDynamic(this, &UGamemodeSelectionWidget::OnPressed_Sandbox);
	}
	else
	{
		return false;
	}

	if (_VersusButton)
	{
		_VersusButton->OnPressed.AddDynamic(this, &UGamemodeSelectionWidget::OnPressed_Versus);
	}
	else
	{
		return false;
	}
	return true;
}

void UGamemodeSelectionWidget::OnPressed_Default()
{
	Cast<UTurretDefenseGameInstance>(UGameplayStatics::GetGameInstance(this))->SetSelectedGamemode(EGamemode::GM_Default);
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenu"));
}

void UGamemodeSelectionWidget::OnPressed_Sandbox()
{
	Cast<UTurretDefenseGameInstance>(UGameplayStatics::GetGameInstance(this))->SetSelectedGamemode(EGamemode::GM_Sandbox);
}

void UGamemodeSelectionWidget::OnPressed_Versus()
{
	Cast<UTurretDefenseGameInstance>(UGameplayStatics::GetGameInstance(this))->SetSelectedGamemode(EGamemode::GM_Versus);
}
