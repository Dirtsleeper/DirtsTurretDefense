// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "HUD/Main/Upgrades/UpgradeTypeEnum.h"
#include "WeaponUpgradeStruct.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Weapon.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FReloadSignature);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIRTSTURRETDEFENSE_API UWeapon : public UActorComponent
{
	GENERATED_BODY()

private:
	bool _bFiring = false;

	bool _bReloading = false;

	bool _bInitialized = false;

	struct FWeaponInfo* _Info;

	FWeaponUpgrade _UpgradeState;

	FTimerHandle FireProjectileTimer;

	UPROPERTY()
	class ATurret* _Turret;

protected:

public:
	FReloadSignature OnReload;

public:
	// Sets default values for this component's properties
	UWeapon();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void InitializeWeapon(struct FWeaponInfo* WeaponInfo);

	void Unlock();

	void Upgrade(EWeaponUpgradeType WeaponUpgrade);

	TSharedPtr<FWeaponInfo> GetInfo();

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

	virtual class AProjectile* SpawnProjectile(FTransform SpawnTransform);

	virtual void OnBeginReload();

	void FinishReloading();

	virtual void OnFinishReloading();

	void StartFireTimer();

	void ClearFireTimer();

	bool IsFireTimerActive();

private:

};
