// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "HUD/Main/Upgrades/UpgradeTypeEnum.h"
#include "DirtsTurretDefense.h"

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "TurretUpgradeStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType, Blueprintable)
struct FTurretUpgrade
{
	GENERATED_BODY()
private:
	TMap<ETurretUpgradeType, uint8> _Prestige;

	TMap<ETurretUpgradeType, uint8> _Upgrade;

protected:

public:

public:
	FTurretUpgrade()
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


	void Prestige(ETurretUpgradeType Upgrade)
	{
		++_Prestige[Upgrade];
		_Upgrade[Upgrade] = 0;
	}

	void Upgrade(ETurretUpgradeType Upgrade)
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

	int32 GetPrestige(ETurretUpgradeType Upgrade)
	{
		return _Prestige[Upgrade];
	}

	int32 GetUpgrade(ETurretUpgradeType Upgrade)
	{
		return _Upgrade[Upgrade];
	}

protected:

private:
	void InitializeMaps()
	{
		for (ETurretUpgradeType Upgrade : EnumGetList<ETurretUpgradeType>(TEXT("ETurretUpgradeType")))
		{
			_Prestige.Add(Upgrade, 0);
			_Upgrade.Add(Upgrade, 0);
		}
	}

public:
	bool operator==(const FTurretUpgrade& other) const
	{
		return GetPrestigeValues() == other.GetPrestigeValues() && GetUpgradeValues() == other.GetUpgradeValues();
	}

};

FORCEINLINE uint32 GetTypeHash(const FTurretUpgrade& s)
{
	return FCrc::MemCrc_DEPRECATED(&s, sizeof(FTurretUpgrade));
}


UCLASS()
class DIRTSTURRETDEFENSE_API UTurretUpgradeStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
	
	
	
	
};
