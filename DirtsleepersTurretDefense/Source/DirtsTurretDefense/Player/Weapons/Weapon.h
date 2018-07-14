// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "HUD/Main/Upgrades/UpgradeTypeEnum.h"
#include "WeaponUpgradeStruct.h"
#include "WeaponInfoStruct.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIRTSTURRETDEFENSE_API UWeapon : public UActorComponent
{
	GENERATED_BODY()

private:
	bool _bFiring = false;

	bool _bReloading = false;

	bool _bInitialized = false;

	FWeaponInfo _Info;

	FWeaponUpgrade _UpgradeState;

	FTimerHandle FireProjectileTimer;

protected:

public:

public:
	// Sets default values for this component's properties
	UWeapon();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitializeWeapon(struct FWeaponInfo WeaponInfo);

	void Unlock();

	void Upgrade(EWeaponUpgradeType WeaponUpgrade);

	FWeaponInfo GetInfo();

	void FirePressed();

	void FireReleased();

	bool IsFiring() { return _bFiring; }

	bool IsReloading() { return _bReloading; }

	void Reload();


	// Weapon Stats
	float GetDamage();

	float GetArmorPenetration();

	float GetFireRate();

	float GetMagazineSize();

	float GetReloadTime();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void OnRegister() override;

	virtual void OnFirePressed();

	virtual void OnFireReleased();

	virtual void FireProjectile();

	virtual void OnBeginReload();

	void FinishReloading();

	virtual void OnFinishReloading();

	void StartFireTimer();

	void ClearFireTimer();

private:

};
