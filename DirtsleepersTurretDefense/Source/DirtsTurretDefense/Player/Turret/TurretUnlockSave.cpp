// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretUnlockSave.h"


UTurretUnlockSave::UTurretUnlockSave()
{
	_Upgrades.Add(ETurretUpgradeType::UT_Health);
	_Upgrades.Add(ETurretUpgradeType::UT_RotationSpeed);
}

void UTurretUnlockSave::UnlockUpgrade(ETurretUpgradeType Upgrade)
{
	_Upgrades.Add(Upgrade);
}

bool UTurretUnlockSave::IsUpgradeUnlocked(ETurretUpgradeType Upgrade)
{
	return _Upgrades.Contains(Upgrade);
}
