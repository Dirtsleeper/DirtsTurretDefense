// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/TD_HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */

class UMainMenuWidget;

UCLASS(Blueprintable)
class DIRTSTURRETDEFENSE_API AMainHUD : public ATD_HUD
{
	GENERATED_BODY()
private:
	UPROPERTY(Category = "WidgetClasses", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UMainMenuWidget> MainMenuClass;

protected:

public:
	UPROPERTY()
	UMainMenuWidget* MainMenu;

public:

protected:
	virtual void BeginPlay() override;

	virtual void CreateWidgets() override;

private:

};
