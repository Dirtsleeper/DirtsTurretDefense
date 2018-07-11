// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TD_HUD.generated.h"

/**
 * 
 */

class USettingsMenuWidget;

UCLASS(Abstract, NotBlueprintable, NotBlueprintType)
class DIRTSTURRETDEFENSE_API ATD_HUD : public AHUD
{
	GENERATED_BODY()
private:
	UPROPERTY(Category = "WidgetClasses", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<USettingsMenuWidget> SettingsMenuClass;

	UPROPERTY()
	USettingsMenuWidget* _SettingsMenu;

protected:

public:
	

public:
	/**
	 * @param ReturnToWidget	Widget to open when the settings menu is closed.
	 */
	void OpenSettingsMenu(class UTD_Widget* ReturnWidget);

	/**
	 * Do not use this pointer to open the settings menu. Use ATD_HUD::OpenSettingsMenu
	 */
	USettingsMenuWidget* GetSettingsMenu();

protected:
	virtual void BeginPlay() override;

	virtual void CreateWidgets();

private:
	
};
