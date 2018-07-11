// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWidgets/LoadWidget.h"
#include "LoadScreenWidget.generated.h"

/**
 * 
 */

class UButton;

UCLASS()
class DIRTSTURRETDEFENSE_API ULoadScreenWidget : public ULoadWidget
{
	GENERATED_BODY()
private:
	UPROPERTY(meta = (BindWidget))
	UButton* _StartNewGameButton;

	UPROPERTY(meta = (BindWidget))
	UButton* _LoadSavedGameButton;

	UPROPERTY(meta = (BindWidget))
	UButton* _SettingsButton;

	UPROPERTY(meta = (BindWidget))
	UButton* _ExitGameButton;

protected:

public:

public:

protected:
	virtual void NativeConstruct() override;

	virtual bool BindButtons() override;

private:
	bool SavedGameExists();

	UFUNCTION()
	void OnPressed_StartNewGame();
	UFUNCTION()
	void OnPressed_LoadSavedGame();
	UFUNCTION()
	void OnPressed_Settings();
	UFUNCTION()
	void OnPressed_ExitGame();
};
