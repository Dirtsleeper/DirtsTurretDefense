// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWidgets/MainWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */

class UButton;

UCLASS()
class DIRTSTURRETDEFENSE_API UMainMenuWidget : public UMainWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(meta = (BindWidget))
	class UPrimaryWeaponSelectionWidget* _PrimaryWeaponSelection;

	UPROPERTY(meta = (BindWidget))
	class USecondaryWeaponSelectionWidget* _SecondaryWeaponSelection;

	UPROPERTY(meta = (BindWidget))
	class USpecialWeaponSelectionWidget* _SpecialWeaponSelection;

	UPROPERTY(meta = (BindWidget))
	class UTurretAttachmentSelectionWidget* _TurretAttachmentSelection;

	UPROPERTY(meta = (BindWidget))
	UButton* _StartMissionButton;

	UPROPERTY(meta = (BindWidget))
	UButton* _MainMenuButton;

protected:

public:

public:
	virtual bool BindButtons() override;

protected:

private:
	UFUNCTION()
	void OnPressed_StartMissionButton();

	UFUNCTION()
	void OnPressed_MainMenuButton();

};
