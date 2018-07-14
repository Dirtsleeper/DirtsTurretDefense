// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponUpgradeSave.h"

#include "Kismet/GameplayStatics.h"
#include "General/Core/TurretDefenseGameInstance.h"


void UWeaponUpgradeSave::UpgradeWeapon(int32 WeaponID, FWeaponUpgrade NewUpgrades)
{
	if (_WeaponUpgrades.Contains(WeaponID))
	{
		_WeaponUpgrades[WeaponID] = NewUpgrades;
	}
	else
	{
		_WeaponUpgrades.Add(WeaponID, NewUpgrades);
	}
}

FWeaponUpgrade UWeaponUpgradeSave::GetUpgrades(int32 WeaponID)
{
	if (_WeaponUpgrades.Contains(WeaponID))
	{
		return _WeaponUpgrades[WeaponID];
	}
	UE_LOG(LogTemp, Error, TEXT("Weapon Upgrades did not contain weapon %d"), WeaponID);
	return FWeaponUpgrade();
}
