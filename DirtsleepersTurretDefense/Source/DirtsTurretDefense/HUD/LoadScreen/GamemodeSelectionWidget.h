// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HUD/TD_Widget.h"
#include "GamemodeSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UGamemodeSelectionWidget : public UTD_Widget
{
	GENERATED_BODY()
private:
	UPROPERTY(meta = (BindWidget))
		UButton* _DefaultButton;
	UPROPERTY(meta = (BindWidget))
		UButton* _SandboxButton;
	UPROPERTY(meta = (BindWidget))
		UButton* _VersusButton;

protected:

public:

public:
	virtual bool BindButtons() override;

protected:

private:
	UFUNCTION()
		void OnPressed_Default();

	UFUNCTION()
		void OnPressed_Sandbox();

	UFUNCTION()
		void OnPressed_Versus();
		
};
