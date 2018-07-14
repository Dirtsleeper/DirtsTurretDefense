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
	int32 PrimaryWeaponID = -1;

	int32 SecondaryWeaponID = -1;

	int32 SpecialWeaponID = -1;

public:
	void SaveTurret(class ATurret* Turret);

protected:

private:
		
};
