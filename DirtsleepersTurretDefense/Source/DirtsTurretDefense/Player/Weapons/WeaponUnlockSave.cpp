// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponUnlockSave.h"


void UWeaponUnlockSave::UnlockWeapon(int32 WeaponID)
{
	_UnlockedWeapons.Add(WeaponID);
}

bool UWeaponUnlockSave::IsWeaponUnlocked(int32 WeaponID)
{
	return _UnlockedWeapons.Contains(WeaponID);
}
