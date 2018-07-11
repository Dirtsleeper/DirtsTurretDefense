// Fill out your copyright notice in the Description page of Project Settings.

#include "PrimaryWeaponSelectionWidget.h"

#include "PrimaryWeaponButton.h"


void UPrimaryWeaponSelectionWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	if (m_DropDown)
	{
		m_DropDown->SetTitleText(FText::FromString(TEXT("Primary Weapons")));
		for (EPrimaryWeapon Weapon : EnumGetList<EPrimaryWeapon>(TEXT("EPrimaryWeapon")))
		{
			UPrimaryWeaponButton* Button = WidgetTree->ConstructWidget<UPrimaryWeaponButton>();
			Button->SetWeapon(Weapon);
			Button->OnPressed_Custom.AddDynamic(this, &UPrimaryWeaponSelectionWidget::EquipWeapon);
			UTextBlock* Text = WidgetTree->ConstructWidget<UTextBlock>();
			Text->SetText(FText::FromString(EnumAsString<EPrimaryWeapon>(TEXT("EPrimaryWeapon"), Weapon, TEXT("PW_"), true)));
			Button->AddChild(Text);
			m_DropDown->AddChild(Button);
		}
	}
}

void UPrimaryWeaponSelectionWidget::EquipWeapon(EPrimaryWeapon Weapon)
{
	m_GameMode->EquipPrimaryWeapon(Weapon);
}
