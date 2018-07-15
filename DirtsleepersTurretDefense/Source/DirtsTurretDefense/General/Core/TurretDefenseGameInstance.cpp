// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretDefenseGameInstance.h"

#include "Engine/DataTable.h"
#include "UObject/ConstructorHelpers.h"
#include "Player/Weapons/WeaponInfoStruct.h"
#include "Game/Combat/CombatInterface.h"
#include "Game/Combat/CombatInfoStruct.h"


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

FWeaponInfo* UTurretDefenseGameInstance::GetWeaponInfoFromDataTable(EWeaponType WeaponType, int32 WeaponID)
{
	if (WeaponID >= 0)
	{
		switch (WeaponType)
		{
		case EWeaponType::Primary:
			return _PrimaryWeaponTable->FindRow<FWeaponInfo>(FName(*FString::FromInt(WeaponID)), FString(""));
		case EWeaponType::Secondary:
			return _SecondaryWeaponTable->FindRow<FWeaponInfo>(FName(*FString::FromInt(WeaponID)), FString(""));
		case EWeaponType::Special:
			return _SpecialWeaponTable->FindRow<FWeaponInfo>(FName(*FString::FromInt(WeaponID)), FString(""));
		case EWeaponType::Enemy:
			return _EnemyWeaponTable->FindRow<FWeaponInfo>(FName(*FString::FromInt(WeaponID)), FString(""));
		}
	}
	UE_LOG(LogTemp, Error, TEXT("Invalid Weapon ID"));
	return new FWeaponInfo();
}

struct FCombatInfo* UTurretDefenseGameInstance::GetCombatInfoFromDataTable(AActor* Actor)
{
	if (ICombatInterface* Interface = Cast<ICombatInterface>(Actor))
	{
		FString Name = Interface->GetEnemyName().ToString();
		Name.ReplaceInline(TEXT(" "), TEXT(""));
		return _CombatInfoTable->FindRow<FCombatInfo>(FName(*Name), FString(""));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Tried to get combat info for an actor that doesn't implement CombatInterface"));
	}
	return nullptr;
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
		UE_LOG(LogTemp, Error, TEXT("Could not find Primary Weapon Data Table. Fix Reference in TurretDefenseGameInstance::StoreWeaponTables"));
	}

	FString SecondaryWeaponTableLocation = TEXT("DataTable'/Game/Player/Weapons/SecondaryWeapons.SecondaryWeapons'");
	ConstructorHelpers::FObjectFinder<UDataTable> SecondaryWeaponTableFinder(*SecondaryWeaponTableLocation);
	if (SecondaryWeaponTableFinder.Succeeded())
	{
		_SecondaryWeaponTable = SecondaryWeaponTableFinder.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find Secondary Weapon Data Table. Fix Reference in TurretDefenseGameInstance::StoreWeaponTables"));
	}

	FString SpecialWeaponTableLocation = TEXT("DataTable'/Game/Player/Weapons/SpecialWeapons.SpecialWeapons'");
	ConstructorHelpers::FObjectFinder<UDataTable> SpecialWeaponTableFinder(*SpecialWeaponTableLocation);
	if (SpecialWeaponTableFinder.Succeeded())
	{
		_SpecialWeaponTable = SpecialWeaponTableFinder.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find Special Weapon Data Table. Fix Reference in TurretDefenseGameInstance::StoreWeaponTables"));
	}

	FString CombatInfoTableLocation = TEXT("DataTable'/Game/Enemies/Enemies.Enemies'");
	ConstructorHelpers::FObjectFinder<UDataTable> CombatInfoTableFinder(*CombatInfoTableLocation);
	if (CombatInfoTableFinder.Succeeded())
	{
		_CombatInfoTable = CombatInfoTableFinder.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find Combat Info Data Table. Fix Reference in TurretDefenseGameInstance::StoreWeaponTables"));
	}

	FString EnemyWeaponTableLocation = TEXT("DataTable'/Game/Enemies/EnemyWeapons.EnemyWeapons'");
	ConstructorHelpers::FObjectFinder<UDataTable> EnemyWeaponTableFinder(*EnemyWeaponTableLocation);
	if (EnemyWeaponTableFinder.Succeeded())
	{
		_EnemyWeaponTable = EnemyWeaponTableFinder.Object;
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find Enemy Weapon Data Table. Fix Reference in TurretDefenseGameInstance::StoreWeaponTables"));
	}
}
