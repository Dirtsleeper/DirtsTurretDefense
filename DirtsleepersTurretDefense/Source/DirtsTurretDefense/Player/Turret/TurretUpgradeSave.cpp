// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretUpgradeSave.h"

#include "DirtsTurretDefense.h"

void UTurretUpgradeSave::UpgradeTurret(ETurretUpgradeType Upgrade, FTurretUpgrade NewUpgrades)
{
	_TurretUpgrades[Upgrade] = NewUpgrades;
}

FTurretUpgrade UTurretUpgradeSave::GetUpgrades(ETurretUpgradeType Upgrade)
{
	return _TurretUpgrades[Upgrade];
}
