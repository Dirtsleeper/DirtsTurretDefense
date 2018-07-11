// Fill out your copyright notice in the Description page of Project Settings.

#include "DropdownMenuWidget.h"


UDropdownMenuWidget::UDropdownMenuWidget()
{
	m_bRequiresFadeAnimation = false;
}

void UDropdownMenuWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (_bFlipWidget)
	{
		FlipWidget();
	}
}

void UDropdownMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	_ButtonContainer->SetVisibility(ESlateVisibility::Collapsed);
}

void UDropdownMenuWidget::NativeOnMouseLeave(const FPointerEvent& InMouseEvent)
{
	Super::NativeOnMouseLeave(InMouseEvent);
	_ButtonContainer->SetVisibility(ESlateVisibility::Collapsed);
}

bool UDropdownMenuWidget::BindButtons()
{
	Super::BindButtons();

	if (_TitleButton)
	{
		_TitleButton->OnPressed.AddDynamic(this, &UDropdownMenuWidget::OnPressed_TitleButton);
	}
	else
	{
		return false;
	}
	return true;
}

void UDropdownMenuWidget::SetTitleText(FText Text)
{
	if (_TitleText)
	{
		_TitleText->SetText(Text);
	}
}

UVerticalBox* UDropdownMenuWidget::GetButtonContainer()
{
	return _ButtonContainer;
}

void UDropdownMenuWidget::AddChild(UWidget* Content)
{
	_ButtonContainer->AddChild(Content);
	if (_bFlipWidget)
	{
		FlipContainerChildren();
	}
}

void UDropdownMenuWidget::OnPressed_TitleButton()
{
	_ButtonContainer->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}

void UDropdownMenuWidget::FlipWidget()
{
	SetRenderAngle(180.f);
	_TitleButton->SetRenderAngle(180.f);
	FlipContainerChildren();
}

void UDropdownMenuWidget::FlipContainerChildren()
{
	for (int32 i = 0; i < _ButtonContainer->GetChildrenCount(); i++)
	{
		_ButtonContainer->GetChildAt(i)->SetRenderAngle(180.f);
	}
}
