// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretSave.h"

#include "Turret.h"
#include "Player/Weapons/WeaponInfoStruct.h"


void UTurretSave::SaveTurret(ATurret* Turret)
{
	if (UWeapon* Primary = Turret->GetPrimaryWeapon())
	{
		PrimaryWeapon = Primary->GetClass();
		PrimaryWeaponID = Primary->GetInfo().ID;
	}
	if (UWeapon* Secondary = Turret->GetSecondaryWeapon())
	{
		SecondaryWeapon = Secondary->GetClass();
		SecondaryWeaponID = Secondary->GetInfo().ID;
	}
	if (UWeapon* Special = Turret->GetSpecialWeapon())
	{
		SpecialWeapon = Special->GetClass();
		SpecialWeaponID = Special->GetInfo().ID;
	}
}
