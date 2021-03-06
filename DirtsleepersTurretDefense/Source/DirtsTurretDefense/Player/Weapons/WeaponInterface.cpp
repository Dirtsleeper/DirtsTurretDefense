// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponInterface.h"
#include "General/Core/TurretDefenseGameInstance.h"

#include "General/Core/TurretDefenseGameInstance.h"
#include "Player/Turret/TurretSave.h"
#include "WeaponInfoStruct.h"
#include "General/Core/Game/Combat/CombatInfoStruct.h"


void IWeaponInterface::IntializeWeapons(UWeapon*& PrimaryWeapon, UWeapon*& SecondaryWeapon, UWeapon*& SpecialWeapon)
{
	FCombatInfo* CombatInfo = GI::GetGameInstance(GetOwner())->GetCombatInfoFromDataTable(GetOwner());
	FWeaponInfo* Info = GI::GetGameInstance(GetOwner())->GetWeaponInfoFromDataTable(EWeaponType::Enemy, CombatInfo->GetWeaponID());
	PrimaryWeapon = NewObject<UWeapon>(GetOwner(), Info->WeaponClass, FName(*Info->Name.ToString()));
	PrimaryWeapon->InitializeWeapon(Info);
	PrimaryWeapon->RegisterComponent();
	GetOwner()->AddOwnedComponent(PrimaryWeapon);
}

// Add default functionality here for any IWeaponInterface functions that are not pure virtual.

void IWeaponInterface::FirePressed()
{
	GetSelectedWeapon()->FirePressed();
}

void IWeaponInterface::FireReleased()
{
	GetSelectedWeapon()->FireReleased();
}

void IWeaponInterface::FireSpecialWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("Impelement FireSpecialWeapon in %s"), *GetOwner()->GetFName().ToString());
}

void IWeaponInterface::Reload()
{
	GetSelectedWeapon()->Reload();
}

void IWeaponInterface::SwitchWeapons()
{
	if (GetSelectedWeapon()->IsFiring())
	{
		FireReleased();
	}
	UE_LOG(LogTemp, Warning, TEXT("Impelement SwitchWeapons in %s"), *GetOwner()->GetFName().ToString());
}

void IWeaponInterface::SelectPrimaryWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("Impelement SelectPrimaryWeapon in %s"), *GetOwner()->GetFName().ToString());
}

void IWeaponInterface::SelectSecondaryWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("Impelement SelectSecondaryWeapon in %s"), *GetOwner()->GetFName().ToString());
}

UWeapon* IWeaponInterface::GetSelectedWeapon()
{
	UE_LOG(LogTemp, Warning, TEXT("Impelement GetSelectedWeapon in %s"), *GetOwner()->GetFName().ToString());
	return nullptr;
}
