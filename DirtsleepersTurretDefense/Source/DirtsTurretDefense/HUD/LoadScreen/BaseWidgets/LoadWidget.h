// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "General/Core/LoadScreen/LoadScreenGameMode.h"
#include "General/Core/LoadScreen/LoadScreenPlayerController.h"
#include "HUD/LoadScreen/LoadScreenHUD.h"

#include "CoreMinimal.h"
#include "HUD/TD_Widget.h"
#include "LoadWidget.generated.h"

/**
 * 
 */

UCLASS(Abstract)
class DIRTSTURRETDEFENSE_API ULoadWidget : public UTD_Widget
{
	GENERATED_BODY()
private:

protected:
	UPROPERTY()
	ALoadScreenGameMode* m_GameMode;

	UPROPERTY()
	ALoadScreenPlayerController* m_PlayerController;

	UPROPERTY()
	ALoadScreenHUD* m_HUD;

public:

public:
	ULoadWidget();

protected:
	void NativeConstruct() override;

private:
	
	
	
};
