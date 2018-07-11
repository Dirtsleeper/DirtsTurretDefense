// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GraphicSettingEnum.h"

#include "CoreMinimal.h"
#include "HUD/TD_Widget.h"
#include "SettingsRowWidget.generated.h"

/**
 * 
 */

class UButton;

UCLASS(Abstract, Blueprintable)
class DIRTSTURRETDEFENSE_API USettingsRowWidget : public UTD_Widget
{
	GENERATED_BODY()
private:
	EGraphicSetting _Setting;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* _SettingText;

	UPROPERTY(meta = (BindWidget))
	UButton* _LowButton;

	UPROPERTY(meta = (BindWidget))
	UButton* _MediumButton;

	UPROPERTY(meta = (BindWidget))
	UButton* _HighButton;

	UPROPERTY(meta = (BindWidget))
	UButton* _UltraButton;

	UPROPERTY()
	TArray<UButton*> _Buttons;

	UPROPERTY()
	class USettingsMenuWidget* _SettingsMenu;

protected:

public:

public:
	virtual void NativeConstruct() override;

	void InitializeRow(EGraphicSetting Setting);

	virtual bool BindButtons() override;

	UButton* GetButton(EGraphicQuality Quality);

	void EnableButtons(UButton* DisabledButton);

protected:

private:
	void SetText(FText NewText);

	UFUNCTION()
	void OnLowPressed();

	UFUNCTION()
	void OnMediumPressed();

	UFUNCTION()
	void OnHighPressed();

	UFUNCTION()
	void OnUltraPressed();
};
