// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Player/Weapons/Weapon.h"
#include "Player/Weapons/WeaponUpgradeStruct.h"

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TurretSave.generated.h"

/**
 * 
 */

UCLASS()
class DIRTSTURRETDEFENSE_API UTurretSave : public USaveGame
{
	GENERATED_BODY()
private:

protected:

public:
	TSubclassOf<UWeapon> PrimaryWeapon;

	FWeaponUpgrade PrimaryUpgrades;

	TSubclassOf<UWeapon> SecondaryWeapon;

	FWeaponUpgrade SecondaryUpgrades;

	TSubclassOf<UWeapon> SpecialWeapon;

public:

protected:

private:
		
};
