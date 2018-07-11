// Fill out your copyright notice in the Description page of Project Settings.

#include "SecondaryWeaponSelectionWidget.h"

#include "SecondaryWeaponButton.h"


void USecondaryWeaponSelectionWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (m_DropDown)
	{
		m_DropDown->SetTitleText(FText::FromString(TEXT("Secondary Weapons")));
		for (ESecondaryWeapon Weapon : EnumGetList<ESecondaryWeapon>(TEXT("ESecondaryWeapon")))
		{
			USecondaryWeaponButton* Button = WidgetTree->ConstructWidget<USecondaryWeaponButton>();
			Button->SetWeapon(Weapon);
			Button->OnPressed_Custom.AddDynamic(this, &USecondaryWeaponSelectionWidget::EquipWeapon);
			UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>();
			Text->SetText(FText::FromString(EnumAsString<ESecondaryWeapon>(TEXT("ESecondaryWeapon"), Weapon, TEXT("SW_"), true)));
			Button->AddChild(Text);
			m_DropDown->AddChild(Button);
		}
	}
}

void USecondaryWeaponSelectionWidget::EquipWeapon(ESecondaryWeapon Weapon)
{
	m_GameMode->EquipSecondaryWeapon(Weapon);
}
