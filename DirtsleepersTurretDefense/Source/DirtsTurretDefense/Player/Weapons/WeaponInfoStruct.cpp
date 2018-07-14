// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponInfoStruct.h"

#include "WeaponUpgradeStruct.h"
#include "HUD/Main/Upgrades/UpgradeTypeEnum.h"
#include "Engine/DataTable.h"
#include "UObject/ConstructorHelpers.h"
#include "Weapon.h"


FWeaponInfo::FWeaponInfo()
{
	WeaponClass = UWeapon::StaticClass();
}

float FWeaponInfo::GetDamage(FWeaponUpgrade Upgrades)
{
	return Damage + Upgrades.GetPrestige(EWeaponUpgradeType::UT_Damage) * Damage_Prestige + Upgrades.GetUpgrade(EWeaponUpgradeType::UT_Damage) * Damage_Upgrade;
}

float FWeaponInfo::GetArmorPenetration(FWeaponUpgrade Upgrades)
{
	return ArmorPenetration + Upgrades.GetPrestige(EWeaponUpgradeType::UT_ArmorPenetration) * ArmorPenetration_Prestige + Upgrades.GetUpgrade(EWeaponUpgradeType::UT_ArmorPenetration) * ArmorPenetration_Upgrade;
}

float FWeaponInfo::GetFireRate(FWeaponUpgrade Upgrades)
{
	return FireRate + Upgrades.GetPrestige(EWeaponUpgradeType::UT_FireRate) * FireRate_Prestige + Upgrades.GetUpgrade(EWeaponUpgradeType::UT_FireRate) * FireRate_Upgrade;
}

float FWeaponInfo::GetMagazineSize(FWeaponUpgrade Upgrades)
{
	return MagazineSize + Upgrades.GetPrestige(EWeaponUpgradeType::UT_MagazineSize) * MagazineSize_Prestige + Upgrades.GetUpgrade(EWeaponUpgradeType::UT_MagazineSize) * MagazineSize_Upgrade;
}

float FWeaponInfo::GetReloadTime(FWeaponUpgrade Upgrades)
{
	return ReloadTime + Upgrades.GetPrestige(EWeaponUpgradeType::UT_ReloadRate) * ReloadTime_Prestige + Upgrades.GetUpgrade(EWeaponUpgradeType::UT_ReloadRate) * ReloadTime_Upgrade;
}

float FWeaponInfo::GetTimeBetweenProjectiles(FWeaponUpgrade Upgrades)
{
	return 60.f / GetFireRate(Upgrades);
}

FProjectileInfo FWeaponInfo::GetProjectileInfo()
{
	return ProjectileInfo;
}
