// Fill out your copyright notice in the Description page of Project Settings.

#include "SpecialWeaponButton.h"




void USpecialWeaponButton::SetWeapon(ESpecialWeapon Weapon)
{
	_Weapon = Weapon;
	OnPressed.AddDynamic(this, &USpecialWeaponButton::Pressed);
}

void USpecialWeaponButton::Pressed()
{
	OnPressed_Custom.Broadcast(_Weapon);
}
