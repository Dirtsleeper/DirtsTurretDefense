// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "HUD/Main/Upgrades/UpgradeTypeEnum.h"

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TurretUnlockSave.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UTurretUnlockSave : public USaveGame
{
	GENERATED_BODY()
private:
	TSet<ETurretUpgradeType> _Upgrades;

protected:

public:

public:
	UTurretUnlockSave();

	void Save();

	void UnlockUpgrade(ETurretUpgradeType Upgrade);

	bool IsUpgradeUnlocked(ETurretUpgradeType Upgrade);

protected:

private:
	
};
