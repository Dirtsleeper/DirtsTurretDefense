// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GraphicSettingEnum.h"
#include "GraphicQualityEnum.h"

#include "CoreMinimal.h"
#include "HUD/TD_Widget.h"
#include "SettingsMenuWidget.generated.h"

/**
 * 
 */

class USettingsRowWidget;

UCLASS()
class DIRTSTURRETDEFENSE_API USettingsMenuWidget : public UTD_Widget
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		bool _bLogConsoleCommands = true;

	UPROPERTY(meta = (BindWidget))
		USettingsRowWidget* _Quality;

	UPROPERTY(meta = (BindWidget))
		USettingsRowWidget* _ResolutionScale;

	UPROPERTY(meta = (BindWidget))
		USettingsRowWidget* _ViewDistance;

	UPROPERTY(meta = (BindWidget))
		USettingsRowWidget* _AntiAliasing;

	UPROPERTY(meta = (BindWidget))
		USettingsRowWidget* _PostProcessing;

	UPROPERTY(meta = (BindWidget))
		USettingsRowWidget* _Shadows;

	UPROPERTY(meta = (BindWidget))
		USettingsRowWidget* _Textures;

	UPROPERTY(meta = (BindWidget))
		USettingsRowWidget* _Effects;

	UPROPERTY(meta = (BindWidget))
		USettingsRowWidget* _Foliage;

	UPROPERTY(meta = (BindWidget))
		UButton* _BackButton;

	UPROPERTY()
		UTD_Widget* _ReturnWidget;

	UPROPERTY()
		class USettingsFile* _SettingsFile;

protected:

public:

public:
	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	void ApplySetting(EGraphicSetting Setting, EGraphicQuality Quality, bool bSave = true);

	void SetReturnWidget(UTD_Widget* ReturnWidget);

	virtual bool BindButtons() override;

protected:

private:
	void SaveSettings();
	
	UFUNCTION()
	void OnBackButtonPressed();
};
