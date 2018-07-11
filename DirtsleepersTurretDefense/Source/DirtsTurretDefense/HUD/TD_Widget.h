// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "DirtsTurretDefense.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TD_Widget.generated.h"

/**
 * 
 */

UCLASS(Abstract, Blueprintable, NotBlueprintType)
class DIRTSTURRETDEFENSE_API UTD_Widget : public UUserWidget
{
	GENERATED_BODY()
private:
	UPROPERTY()
	UWidgetAnimation* _FadeAnimationPtr;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool m_bRequiresFadeAnimation = false;

public:
	virtual void Open(bool bFadeIn = false);

	virtual void Close(bool bFadeOut = false);

protected:
	virtual void NativeConstruct() override;

	virtual void PreFadeIn();

	UFUNCTION()
	virtual void PostFadeIn();

	virtual void PreFadeOut();

	UFUNCTION()
	virtual void PostFadeOut();

	virtual bool BindButtons();

private:
	void FadeIn();

	void FadeOut();
	
	void StoreFadeAnimation();
};
