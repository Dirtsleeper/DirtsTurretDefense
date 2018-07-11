// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "General/Core/MainMenu/MainMenuGameMode.h"
#include "General/Core/MainMenu/MainMenuPlayerController.h"
#include "HUD/Main/MainHUD.h"

#include "CoreMinimal.h"
#include "HUD/TD_Widget.h"
#include "MainWidget.generated.h"

/**
 * 
 */

UCLASS(Abstract)
class DIRTSTURRETDEFENSE_API UMainWidget : public UTD_Widget
{
	GENERATED_BODY()
private:

protected:
	UPROPERTY()
	AMainMenuGameMode* m_GameMode;

	UPROPERTY()
	AMainMenuPlayerController* m_PlayerController;

	UPROPERTY()
	AMainHUD* m_HUD;

public:

public:
	UMainWidget();

protected:
	void NativeConstruct() override;

private:
	
	
	
};
