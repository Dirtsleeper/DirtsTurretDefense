// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponInterface.h"
#include "General/Core/TurretDefenseGameInstance.h"

#include "General/Core/TurretDefenseGameInstance.h"
#include "Player/Turret/TurretSave.h"


void IWeaponInterface::IntializeWeapons(UWeapon*& PrimaryWeapon, UWeapon*& SecondaryWeapon, UWeapon*& SpecialWeapon)
{
	if (UGameplayStatics::DoesSaveGameExist(TEXT("PlayerTurret"), GI::GetGameInstance(GetOwner())->GetSaveSlot()))
	{
		UTurretSave* PlayerTurretSave = Cast<UTurretSave>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerTurret"), GI::GetGameInstance(GetOwner())->GetSaveSlot()));

		if (PlayerTurretSave->PrimaryWeapon)
		{
			PrimaryWeapon = NewObject<UWeapon>(GetOwner(), PlayerTurretSave->PrimaryWeapon.Get());
			PrimaryWeapon->InitializeUpgrades(PlayerTurretSave->PrimaryUpgrades);
			PrimaryWeapon->RegisterComponent();
			GetOwner()->AddOwnedComponent(PrimaryWeapon);
		}
		if (PlayerTurretSave->SecondaryWeapon)
		{
			SecondaryWeapon = NewObject<UWeapon>(GetOwner(), PlayerTurretSave->SecondaryWeapon.Get(), TEXT("SecondaryWeapon"));
			SecondaryWeapon->InitializeUpgrades(PlayerTurretSave->SecondaryUpgrades);
			SecondaryWeapon->RegisterComponent();
			GetOwner()->AddOwnedComponent(SecondaryWeapon);
		}
		if (PlayerTurretSave->SpecialWeapon)
		{
			SpecialWeapon = NewObject<UWeapon>(GetOwner(), PlayerTurretSave->SpecialWeapon.Get(), TEXT("SpecialWeapon"));
			SpecialWeapon->RegisterComponent();
			GetOwner()->AddOwnedComponent(SpecialWeapon);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find Player Turret Save."));
	}
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

AActor* IWeaponInterface::GetOwner()
{
	return Cast<AActor>(this);
}
