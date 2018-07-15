// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GamemodeEnum.h"
#include "Kismet/GameplayStatics.h"
#include "Utils/SaveManager.h"
#include "Player/Weapons/WeaponTypeEnum.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TurretDefenseGameInstance.generated.h"

/**
 * 
 */

class UTurretDefenseGameInstance;

typedef UTurretDefenseGameInstance GI;

UCLASS()
class DIRTSTURRETDEFENSE_API UTurretDefenseGameInstance : public UGameInstance
{
	GENERATED_BODY()
private:
	UPROPERTY()
	class UDataTable* _PrimaryWeaponTable;
	UPROPERTY()
	class UDataTable* _SecondaryWeaponTable;
	UPROPERTY()
	class UDataTable* _SpecialWeaponTable;
	UPROPERTY()
	class UDataTable* _EnemyWeaponTable;
	UPROPERTY()
	class UDataTable* _CombatInfoTable;

protected:
	EGamemode m_SelectedGamemode = EGamemode::GM_Default;

public:

public:
	static FORCEINLINE UTurretDefenseGameInstance* GetGameInstance(UObject* WorldContextObject)
	{
		return Cast<UTurretDefenseGameInstance>(UGameplayStatics::GetGameInstance(WorldContextObject));
	}

	UTurretDefenseGameInstance();

	virtual void Init() override;

	void SetSelectedGamemode(EGamemode NewGamemode);

	struct FWeaponInfo* GetWeaponInfoFromDataTable(EWeaponType WeaponType, int32 WeaponID);

	struct FCombatInfo* GetCombatInfoFromDataTable(AActor* Actor);

protected:

private:
	void StoreWeaponTables();

};
