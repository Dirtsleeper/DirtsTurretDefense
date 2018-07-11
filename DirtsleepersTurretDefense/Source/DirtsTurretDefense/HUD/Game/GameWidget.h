// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "General/Core/Game/GameplayGameMode.h"
#include "General/Core/Game/GameplayPlayerController.h"

#include "CoreMinimal.h"
#include "HUD/TD_Widget.h"
#include "GameWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class DIRTSTURRETDEFENSE_API UGameWidget : public UTD_Widget
{
	GENERATED_BODY()
private:

protected:
	UPROPERTY()
	AGameplayGameMode* GameMode;

	UPROPERTY()
	AGameplayPlayerController* PlayerController;

	UPROPERTY()
	AGameHUD* HUD;

public:

public:
	UGameWidget();

protected:
	virtual void NativeConstruct() override;

private:
	
	
	
};
