// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretDefenseGameInstance.h"

#include "Engine/DataTable.h"
#include "UObject/ConstructorHelpers.h"
#include "Player/Weapons/WeaponInfoStruct.h"


UTurretDefenseGameInstance::UTurretDefenseGameInstance()
{
	StoreWeaponTables();
}

void UTurretDefenseGameInstance::Init()
{

}

void UTurretDefenseGameInstance::SetSelectedGamemode(EGamemode NewGamemode)
{
	m_SelectedGamemode = NewGamemode;
}

struct FWeaponInfo UTurretDefenseGameInstance::GetWeaponInfoFromDataTable(EWeaponType WeaponType, int32 WeaponID)
{
	switch (WeaponType)
	{
	case EWeaponType::Primary:
		break;
	case EWeaponType::Secondary:
		break;
	case EWeaponType::Special:
		break;
	}
	return FWeaponInfo();
}

void UTurretDefenseGameInstance::StoreWeaponTables()
{
	FString PrimaryWeaponTableLocation = TEXT("DataTable'/Game/Player/Weapons/PrimaryWeapons.PrimaryWeapons'");
	ConstructorHelpers::FObjectFinder<UDataTable> PrimaryWeaponTableFinder(*PrimaryWeaponTableLocation);
	if (PrimaryWeaponTableFinder.Succeeded())
	{
		_PrimaryWeaponTable = PrimaryWeaponTableFinder.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find Primary Weapon Data Table. Fix Reference in FSaveManager::StoreWeaponTables"));
	}

	FString SecondaryWeaponTableLocation = TEXT("DataTable'/Game/Player/Weapons/SecondaryWeapons.SecondaryWeapons'");
	ConstructorHelpers::FObjectFinder<UDataTable> SecondaryWeaponTableFinder(*SecondaryWeaponTableLocation);
	if (SecondaryWeaponTableFinder.Succeeded())
	{
		_SecondaryWeaponTable = SecondaryWeaponTableFinder.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find Secondary Weapon Data Table. Fix Reference in FSaveManager::StoreWeaponTables"));
	}

	FString SpecialWeaponTableLocation = TEXT("DataTable'/Game/Player/Weapons/SpecialWeapons.SpecialWeapons'");
	ConstructorHelpers::FObjectFinder<UDataTable> SpecialWeaponTableFinder(*SpecialWeaponTableLocation);
	if (SpecialWeaponTableFinder.Succeeded())
	{
		_SpecialWeaponTable = SpecialWeaponTableFinder.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find Special Weapon Data Table. Fix Reference in FSaveManager::StoreWeaponTables"));
	}
}
