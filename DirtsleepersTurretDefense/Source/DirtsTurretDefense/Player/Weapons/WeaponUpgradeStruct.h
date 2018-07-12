// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "WeaponUpgradeEnum.h"

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
	TMap<EWeaponUpgrade, uint8> _Prestige;

	TMap<EWeaponUpgrade, uint8> _Upgrade;

protected:

public:
	
public:
	void Prestige(EWeaponUpgrade Upgrade)
	{
		++_Prestige[Upgrade];
		_Upgrade[Upgrade] = 0;
	}

	void Upgrade(EWeaponUpgrade Upgrade)
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

	int32 GetPrestige(EWeaponUpgrade Upgrade)
	{
		return _Prestige[Upgrade];
	}

	int32 GetUpgrade(EWeaponUpgrade Upgrade)
	{
		return _Upgrade[Upgrade];
	}

protected:

private:
	void InitializeMaps()
	{
		for (EWeaponUpgrade Upgrade : EnumGetList<EWeaponUpgrade>(TEXT("EWeaponUpgrade")))
		{
			_Prestige.Add(Upgrade, 0);
			_Upgrade.Add(Upgrade, 0);
		}
	}

};

UCLASS()
class DIRTSTURRETDEFENSE_API UWeaponUpgradeStruct : public UUserDefinedStruct
{
	GENERATED_BODY()	
	
};
