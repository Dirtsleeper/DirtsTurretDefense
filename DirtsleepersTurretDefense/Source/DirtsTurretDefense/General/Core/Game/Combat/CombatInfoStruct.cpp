// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatInfoStruct.h"

#include "BehaviorTree/BehaviorTree.h"


float FCombatInfo::GetHealth()
{
	return Health;
}

float FCombatInfo::GetArmor()
{
	return Armor;
}

float FCombatInfo::GetShield()
{
	return Shield;
}

float FCombatInfo::GetShieldRegen()
{
	return ShieldRegen;
}

int32 FCombatInfo::GetWeaponID()
{
	return WeaponID;
}

UBehaviorTree* FCombatInfo::GetBehaviorTree()
{
	return BehaviorTree;
}
