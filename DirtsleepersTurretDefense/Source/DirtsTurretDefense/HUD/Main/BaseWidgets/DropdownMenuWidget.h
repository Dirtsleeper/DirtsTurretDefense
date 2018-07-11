// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Components/VerticalBox.h"

#include "CoreMinimal.h"
#include "MainWidget.h"
#include "DropdownMenuWidget.generated.h"

/**
 * 
 */

UCLASS()
class DIRTSTURRETDEFENSE_API UDropdownMenuWidget : public UMainWidget
{
	GENERATED_BODY()
private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* _TitleText;

	UPROPERTY(meta = (BindWidget))
	UButton* _TitleButton;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* _ButtonContainer;

	UPROPERTY()
	UButton* _SelectedButton;

protected:

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool _bFlipWidget = false;

public:
	UDropdownMenuWidget();

	virtual void NativePreConstruct() override;

	virtual void NativeConstruct() override;

	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;

	virtual bool BindButtons() override;

	void SetTitleText(FText Text);

	UVerticalBox* GetButtonContainer();

	void AddChild(UWidget* Content);

protected:

private:
	UFUNCTION()
	void OnPressed_TitleButton();

	void FlipWidget();

	void FlipContainerChildren();
};
