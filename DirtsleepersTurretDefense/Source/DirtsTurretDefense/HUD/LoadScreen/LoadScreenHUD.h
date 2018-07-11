// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/TD_HUD.h"
#include "LoadScreenHUD.generated.h"

/**
 * 
 */
class ULoadScreenWidget;
class ULoadGameWidget;
class UGamemodeSelectionWidget;

UCLASS(Blueprintable)
class DIRTSTURRETDEFENSE_API ALoadScreenHUD : public ATD_HUD
{
	GENERATED_BODY()
private:

protected:

public:
	UPROPERTY(Category = "WidgetClasses", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ULoadScreenWidget> LoadScreenClass;
	UPROPERTY(Category = "WidgetClasses", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<ULoadGameWidget> LoadGameClass;
	UPROPERTY(Category = "WidgetClasses", EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<UGamemodeSelectionWidget> GamemodeSelectionMenuClass;

public:
	virtual void BeginPlay() override;

	virtual void CreateWidgets() override;
	UPROPERTY()
		ULoadScreenWidget* LoadScreen;

	UPROPERTY()
		ULoadGameWidget* LoadGame;

	UPROPERTY()
		UGamemodeSelectionWidget* GamemodeSelectionMenu;

protected:

private:
	
	
	
};
