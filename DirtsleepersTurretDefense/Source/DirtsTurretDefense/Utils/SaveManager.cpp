
#include "SaveManager.h"

#include "Misc/CoreDelegates.h"
#include "Kismet/GameplayStatics.h"
#include "Player/Weapons/WeaponUnlockSave.h"
#include "Player/Weapons/WeaponUpgradeSave.h"
#include "Player/Turret/TurretUpgradeSave.h"
#include "Player/Turret/TurretUnlockSave.h"
#include "Player/Turret/Turret.h"
#include "Player/Turret/TurretSave.h"

namespace
{
	FString GetTurretSlot() { return FString(TEXT("Turret")); }
	FString GetWeaponUnlockSlot() { return FString(TEXT("WeaponUnlocks")); }
	FString GetWeaponUpgradeSlot() { return FString(TEXT("WeaponUpgrades")); }
	FString GetTurretUnlockSlot() { return FString(TEXT("TurretUnlocks")); }
	FString GetTurretUpgradeSlot() { return FString(TEXT("TurretUpgrades")); }
}

FSaveManager* FSaveManager::_singleton = nullptr;

FSaveManager::FSaveManager()
{
	LoadSaveFiles();
}

FSaveManager& FSaveManager::Get()
{
	if (!_singleton)
	{
		_singleton = new FSaveManager();
		FCoreDelegates::OnExit.AddStatic(Destroy);
	}
	return *_singleton;
}

void FSaveManager::SetSaveSlot(int32 NewSaveSlot)
{
	if (NewSaveSlot != _CurrentSaveSlot)
	{
		_CurrentSaveSlot = NewSaveSlot;
		LoadSaveFiles();
	}
}

int32 FSaveManager::GetSaveSlot()
{
	return _CurrentSaveSlot;
}

void FSaveManager::SaveTurret(class ATurret* Turret)
{
	if (Turret)
	{
		if (!_TurretSave)
		{
			LoadTurret();
		}
		if (Turret->GetPrimaryWeapon())
		{
			_TurretSave->PrimaryWeapon = Turret->GetPrimaryWeapon()->GetClass();
			_TurretSave->PrimaryWeaponID = Turret->GetPrimaryWeapon()->GetInfo().ID;
		}
		if (Turret->GetSecondaryWeapon())
		{
			_TurretSave->SecondaryWeapon = Turret->GetSecondaryWeapon()->GetClass();
			_TurretSave->SecondaryWeaponID = Turret->GetSecondaryWeapon()->GetInfo().ID;
		}
		if (Turret->GetSpecialWeapon())
		{
			_TurretSave->SpecialWeapon = Turret->GetSpecialWeapon()->GetClass();
			_TurretSave->SpecialWeaponID = Turret->GetSpecialWeapon()->GetInfo().ID;
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Attempted to save an invalid turret."));
	}
}

void FSaveManager::UnlockWeapon(int32 WeaponID)
{
	_WeaponUnlocks->UnlockWeapon(WeaponID);
}

bool FSaveManager::IsWeaponUnlocked(int32 WeaponID)
{
	return _WeaponUnlocks->IsWeaponUnlocked(WeaponID);
}

void FSaveManager::UpgradeWeapon(int32 WeaponID, FWeaponUpgrade WeaponUpgrades)
{
	_WeaponUpgrades->UpgradeWeapon(WeaponID, WeaponUpgrades);
}

FWeaponUpgrade FSaveManager::GetWeaponUpgrades(int32 WeaponID)
{
	return _WeaponUpgrades->GetUpgrades(WeaponID);
}

void FSaveManager::UnlockTurretUpgrade(ETurretUpgradeType Upgrade)
{
	_TurretUnlocks->UnlockUpgrade(Upgrade);
}

bool FSaveManager::IsTurretUpgradeUnlocked(ETurretUpgradeType Upgrade)
{
	return _TurretUnlocks->IsUpgradeUnlocked(Upgrade);
}

void FSaveManager::UpgradeTurret(ETurretUpgradeType Upgrade, FTurretUpgrade TurretUpgrades)
{
	_TurretUpgrades->UpgradeTurret(Upgrade, TurretUpgrades);
}

FTurretUpgrade FSaveManager::GetTurretUpgrades(ETurretUpgradeType Upgrade)
{
	return _TurretUpgrades->GetUpgrades(Upgrade);
}

UTurretSave* FSaveManager::GetTurretSave()
{
	LoadTurret();
	return _TurretSave;
}

void FSaveManager::SaveWeaponUnlocks()
{
	UGameplayStatics::SaveGameToSlot(_WeaponUnlocks, GetWeaponUnlockSlot(), GetSaveSlot());
}

void FSaveManager::SaveWeaponUpgrades()
{
	UGameplayStatics::SaveGameToSlot(_WeaponUpgrades, GetWeaponUpgradeSlot(), GetSaveSlot());
}

void FSaveManager::SaveTurretUnlocks()
{
	UGameplayStatics::SaveGameToSlot(_TurretUnlocks, GetTurretUnlockSlot(), GetSaveSlot());
}

void FSaveManager::SaveTurretUpgrades()
{
	UGameplayStatics::SaveGameToSlot(_TurretUpgrades, GetTurretUpgradeSlot(), GetSaveSlot());
}

void FSaveManager::Destroy()
{
	delete _singleton;
	_singleton = nullptr;
}

void FSaveManager::LoadSaveFiles()
{
	LoadWeaponUnlocks();
	LoadWeaponUpgrades();
	LoadTurretUnlocks();
	LoadTurretUpgrades();
}

void FSaveManager::LoadTurret()
{
	if (UGameplayStatics::DoesSaveGameExist(GetTurretSlot(), GetSaveSlot()))
	{
		_TurretSave = Cast<UTurretSave>(UGameplayStatics::LoadGameFromSlot(GetTurretSlot(), GetSaveSlot()));
	}
	else
	{
		_TurretSave = Cast<UTurretSave>(UGameplayStatics::CreateSaveGameObject(UTurretSave::StaticClass()));

		// Temporary
		_TurretSave->PrimaryWeapon = UWeapon::StaticClass();
		_TurretSave->PrimaryWeaponID = 0;
	}
}

void FSaveManager::LoadWeaponUnlocks()
{
	if (UGameplayStatics::DoesSaveGameExist(GetWeaponUnlockSlot(), GetSaveSlot()))
	{
		_WeaponUnlocks = Cast<UWeaponUnlockSave>(UGameplayStatics::LoadGameFromSlot(GetWeaponUnlockSlot(), GetSaveSlot()));
	}
	else
	{
		_WeaponUnlocks = Cast<UWeaponUnlockSave>(UGameplayStatics::CreateSaveGameObject(UWeaponUnlockSave::StaticClass()));
		SaveWeaponUnlocks();
	}
}

void FSaveManager::LoadWeaponUpgrades()
{
	if (UGameplayStatics::DoesSaveGameExist(GetWeaponUpgradeSlot(), GetSaveSlot()))
	{
		_WeaponUpgrades = Cast<UWeaponUpgradeSave>(UGameplayStatics::LoadGameFromSlot(GetWeaponUpgradeSlot(), GetSaveSlot()));
	}
	else
	{
		_WeaponUpgrades = Cast<UWeaponUpgradeSave>(UGameplayStatics::CreateSaveGameObject(UWeaponUpgradeSave::StaticClass()));
		SaveWeaponUpgrades();
	}
}

void FSaveManager::LoadTurretUnlocks()
{
	if (UGameplayStatics::DoesSaveGameExist(GetTurretUnlockSlot(), GetSaveSlot()))
	{
		_TurretUnlocks = Cast<UTurretUnlockSave>(UGameplayStatics::LoadGameFromSlot(GetTurretUnlockSlot(), GetSaveSlot()));
	}
	else
	{
		_TurretUnlocks = Cast<UTurretUnlockSave>(UGameplayStatics::CreateSaveGameObject(UTurretUnlockSave::StaticClass()));
		SaveTurretUnlocks();
	}
}

void FSaveManager::LoadTurretUpgrades()
{
	if (UGameplayStatics::DoesSaveGameExist(GetTurretUpgradeSlot(), GetSaveSlot()))
	{
		_TurretUpgrades = Cast<UTurretUpgradeSave>(UGameplayStatics::LoadGameFromSlot(GetTurretUpgradeSlot(), GetSaveSlot()));
	}
	else
	{
		_TurretUpgrades = Cast<UTurretUpgradeSave>(UGameplayStatics::CreateSaveGameObject(UTurretUpgradeSave::StaticClass()));
		SaveTurretUpgrades();
	}
}
