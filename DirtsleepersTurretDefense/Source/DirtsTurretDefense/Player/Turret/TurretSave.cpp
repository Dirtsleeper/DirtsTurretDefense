// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretSave.h"

#include "Turret.h"
#include "Player/Weapons/WeaponInfoStruct.h"


void UTurretSave::SaveTurret(ATurret* Turret)
{
	if (UWeapon* Primary = Turret->GetPrimaryWeapon())
	{
		PrimaryWeaponID = Primary->GetInfo()->ID;
	}
	if (UWeapon* Secondary = Turret->GetSecondaryWeapon())
	{
		SecondaryWeaponID = Secondary->GetInfo()->ID;
	}
	if (UWeapon* Special = Turret->GetSpecialWeapon())
	{
		SpecialWeaponID = Special->GetInfo()->ID;
	}
}
