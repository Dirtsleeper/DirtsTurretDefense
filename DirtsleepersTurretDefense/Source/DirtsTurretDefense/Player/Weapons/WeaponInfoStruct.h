// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"
#include "Projectiles/ProjectileInfoStruct.h"
#include "Templates/SubclassOf.h"

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "WeaponInfoStruct.generated.h"

/**
 * 
 */

struct FWeaponUpgrade;

USTRUCT(BlueprintType)
struct FWeaponInfo : public FTableRowBase
{
	GENERATED_BODY()
private:

public:
	UPROPERTY(Category = Default, EditAnywhere, BlueprintReadOnly)
		int32 ID = -1;
	UPROPERTY(Category = Default, EditAnywhere, BlueprintReadOnly)
		FText Name = FText::FromString(TEXT("Weapon Name"));
	UPROPERTY(Category = Default, EditAnywhere, BlueprintReadOnly)
		FText FlavorText = FText::FromString(TEXT("Flavor Text"));
	UPROPERTY(Category = Default, EditAnywhere, BlueprintReadOnly)
		int32 UnlockCost = 0;
	UPROPERTY(Category = Default, EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class UWeapon> WeaponClass;

protected:
	UPROPERTY(Category = "Damage", EditAnywhere, BlueprintReadOnly)
		float Damage = 10.f;
	UPROPERTY(Category = "Damage", EditAnywhere, BlueprintReadOnly)
		float Damage_Upgrade = 5.f;
	UPROPERTY(Category = "Damage", EditAnywhere, BlueprintReadOnly)
		float Damage_Prestige = 10.f;

	UPROPERTY(Category = "ArmorPenetration", EditAnywhere, BlueprintReadOnly)
		float ArmorPenetration = 0.f;
	UPROPERTY(Category = "ArmorPenetration", EditAnywhere, BlueprintReadOnly)
		float ArmorPenetration_Upgrade = 1.f;
	UPROPERTY(Category = "ArmorPenetration", EditAnywhere, BlueprintReadOnly)
		float ArmorPenetration_Prestige = 5.f;

	UPROPERTY(Category = "FireRate", EditAnywhere, BlueprintReadOnly)
		float FireRate = 60.f;
	UPROPERTY(Category = "FireRate", EditAnywhere, BlueprintReadOnly)
		float FireRate_Upgrade = 10.f;
	UPROPERTY(Category = "FireRate", EditAnywhere, BlueprintReadOnly)
		float FireRate_Prestige = 20.f;

	UPROPERTY(Category = "MagazineSize", EditAnywhere, BlueprintReadOnly)
		float MagazineSize = 20.f;
	UPROPERTY(Category = "MagazineSize", EditAnywhere, BlueprintReadOnly)
		float MagazineSize_Upgrade = 5.f;
	UPROPERTY(Category = "MagazineSize", EditAnywhere, BlueprintReadOnly)
		float MagazineSize_Prestige = 10.f;

	UPROPERTY(Category = "ReloadTime", EditAnywhere, BlueprintReadOnly)
		float ReloadTime = 0.5f;
	UPROPERTY(Category = "ReloadTime", EditAnywhere, BlueprintReadOnly)
		float ReloadTime_Upgrade = -0.05f;
	UPROPERTY(Category = "ReloadTime", EditAnywhere, BlueprintReadOnly)
		float ReloadTime_Prestige = -0.1f;

	UPROPERTY(Category = "Projectile", EditAnywhere, BlueprintReadOnly)
		FProjectileInfo ProjectileInfo;

public:
	FWeaponInfo();

	float GetDamage(FWeaponUpgrade Upgrades);

	float GetArmorPenetration(FWeaponUpgrade Upgrades);

	float GetFireRate(FWeaponUpgrade Upgrades);

	float GetMagazineSize(FWeaponUpgrade Upgrades);

	float GetReloadTime(FWeaponUpgrade Upgrades);

	float GetTimeBetweenProjectiles(FWeaponUpgrade Upgrades);

	FProjectileInfo GetProjectileInfo();

protected:

private:
};

UCLASS()
class DIRTSTURRETDEFENSE_API UWeaponInfoStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
	
	
	
	
};
