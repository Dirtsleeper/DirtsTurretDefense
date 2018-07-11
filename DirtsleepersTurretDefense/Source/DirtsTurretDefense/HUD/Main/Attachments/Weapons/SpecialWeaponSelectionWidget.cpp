// Fill out your copyright notice in the Description page of Project Settings.

#include "SpecialWeaponSelectionWidget.h"

#include "SpecialWeaponButton.h"

void USpecialWeaponSelectionWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (m_DropDown)
	{
		m_DropDown->SetTitleText(FText::FromString(TEXT("Special Weapons")));
		for (ESpecialWeapon Weapon : EnumGetList<ESpecialWeapon>(TEXT("ESpecialWeapon")))
		{
			USpecialWeaponButton* Button = WidgetTree->ConstructWidget<USpecialWeaponButton>();
			Button->SetWeapon(Weapon);
			Button->OnPressed_Custom.AddDynamic(this, &USpecialWeaponSelectionWidget::EquipWeapon);
			UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>();
			Text->SetText(FText::FromString(EnumAsString<ESpecialWeapon>(TEXT("ESpecialWeapon"), Weapon, TEXT("SW_"), true)));
			Button->AddChild(Text);
			m_DropDown->AddChild(Button);
		}
	}
}

void USpecialWeaponSelectionWidget::EquipWeapon(ESpecialWeapon Weapon)
{
	m_GameMode->EquipSpecialWeapon(Weapon);
}

