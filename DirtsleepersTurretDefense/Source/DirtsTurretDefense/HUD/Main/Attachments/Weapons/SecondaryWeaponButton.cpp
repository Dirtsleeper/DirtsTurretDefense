// Fill out your copyright notice in the Description page of Project Settings.

#include "SecondaryWeaponButton.h"




void USecondaryWeaponButton::SetWeapon(ESecondaryWeapon Weapon)
{
	_Weapon = Weapon;
	OnPressed.AddDynamic(this, &USecondaryWeaponButton::Pressed);
}

void USecondaryWeaponButton::Pressed()
{
	OnPressed_Custom.Broadcast(_Weapon);
}
