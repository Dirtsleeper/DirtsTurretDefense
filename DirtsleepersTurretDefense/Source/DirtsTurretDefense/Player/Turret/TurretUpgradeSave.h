// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "HUD/Main/Upgrades/UpgradeTypeEnum.h"
#include "TurretUpgradeStruct.h"

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TurretUpgradeSave.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UTurretUpgradeSave : public USaveGame
{
	GENERATED_BODY()
private:
	TMap<ETurretUpgradeType, FTurretUpgrade> _TurretUpgrades;

protected:

public:

public:
	void UpgradeTurret(ETurretUpgradeType Upgrade, FTurretUpgrade NewUpgrades);

	FTurretUpgrade GetUpgrades(ETurretUpgradeType Upgrade);

protected:

private:
	
	
	
};
