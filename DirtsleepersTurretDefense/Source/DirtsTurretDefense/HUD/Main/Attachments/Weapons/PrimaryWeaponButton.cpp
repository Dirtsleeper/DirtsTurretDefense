// Fill out your copyright notice in the Description page of Project Settings.

#include "PrimaryWeaponButton.h"

void UPrimaryWeaponButton::SetWeapon(EPrimaryWeapon Weapon)
{
	_Weapon = Weapon;
	OnPressed.AddDynamic(this, &UPrimaryWeaponButton::Pressed);
}

void UPrimaryWeaponButton::Pressed()
{
	OnPressed_Custom.Broadcast(_Weapon);
}
