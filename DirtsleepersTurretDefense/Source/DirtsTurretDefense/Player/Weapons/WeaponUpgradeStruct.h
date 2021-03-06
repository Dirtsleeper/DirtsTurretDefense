// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "HUD/Main/Upgrades/UpgradeTypeEnum.h"

#include "DirtsTurretDefense.h"
#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "WeaponUpgradeStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType, Blueprintable)
struct FWeaponUpgrade
{
	GENERATED_BODY()
private:
	TMap<EWeaponUpgradeType, uint8> _Prestige;

	TMap<EWeaponUpgradeType, uint8> _Upgrade;

protected:

public:
	
	
public:
	FWeaponUpgrade()
	{
		InitializeMaps();
	}

	// For == Check
	TArray<uint8> GetPrestigeValues() const
	{
		TArray<uint8> Values;
		_Prestige.GenerateValueArray(Values);
		return Values;
	}

	// For == Check
	TArray<uint8> GetUpgradeValues() const
	{
		TArray<uint8> Values;
		_Upgrade.GenerateValueArray(Values);
		return Values;
	}

	void Prestige(EWeaponUpgradeType Upgrade)
	{
		++_Prestige[Upgrade];
		_Upgrade[Upgrade] = 0;
	}

	void Upgrade(EWeaponUpgradeType Upgrade)
	{
		if (_Upgrade[Upgrade] == 5)
		{
			Prestige(Upgrade);
		}
		else
		{
			++_Upgrade[Upgrade];
		}
	}

	int32 GetPrestige(EWeaponUpgradeType Upgrade)
	{
		return _Prestige[Upgrade];
	}

	int32 GetUpgrade(EWeaponUpgradeType Upgrade)
	{
		return _Upgrade[Upgrade];
	}

protected:

private:
	void InitializeMaps()
	{
		for (EWeaponUpgradeType Upgrade : EnumGetList<EWeaponUpgradeType>(TEXT("EWeaponUpgradeType")))
		{
			_Prestige.Add(Upgrade, 0);
			_Upgrade.Add(Upgrade, 0);
		}
	}

	bool operator==(const FWeaponUpgrade& other) const
	{
		return GetPrestigeValues() == other.GetPrestigeValues() && GetUpgradeValues() == other.GetUpgradeValues();
	}
};

FORCEINLINE uint32 GetTypeHash(const FWeaponUpgrade& s)
{
	return FCrc::MemCrc_DEPRECATED(&s, sizeof(FWeaponUpgrade));
}

UCLASS()
class DIRTSTURRETDEFENSE_API UWeaponUpgradeStruct : public UUserDefinedStruct
{
	GENERATED_BODY()	
	
};
