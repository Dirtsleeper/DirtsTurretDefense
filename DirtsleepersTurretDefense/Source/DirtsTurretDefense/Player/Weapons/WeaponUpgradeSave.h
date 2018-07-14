// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "WeaponUpgradeStruct.h"

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "WeaponUpgradeSave.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UWeaponUpgradeSave : public USaveGame
{
	GENERATED_BODY()
private:
	TMap<int32, FWeaponUpgrade> _WeaponUpgrades;

protected:

public:
	void UpgradeWeapon(int32 WeaponID, FWeaponUpgrade NewUpgrades);

	FWeaponUpgrade GetUpgrades(int32 WeaponID);

public:

protected:

private:
	
	
	
};
