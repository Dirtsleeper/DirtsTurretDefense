// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"

#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UWeapon::UWeapon()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeapon::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UWeapon::OnRegister()
{
	Super::OnRegister();
	
	if (!_bInitialized)
	{
		UE_LOG(LogTemp, Error, TEXT("Initializeneeds called on %s before RegisterComponent"), *GetFName().ToString());
	}
}

void UWeapon::OnFirePressed()
{
	if (!_bReloading)
	{
		FireProjectile();
		StartFireTimer();
	}
}

void UWeapon::OnFireReleased()
{
	ClearFireTimer();
}

void UWeapon::FireProjectile()
{

}

void UWeapon::OnBeginReload()
{

}

void UWeapon::FinishReloading()
{
	OnFinishReloading();
	_bReloading = false;
}

void UWeapon::OnFinishReloading()
{

}

void UWeapon::StartFireTimer()
{
	GetWorld()->GetTimerManager().SetTimer(FireProjectileTimer, this, &UWeapon::FireProjectile, _Info.GetTimeBetweenProjectiles(_UpgradeState));
}

void UWeapon::ClearFireTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(FireProjectileTimer);
}

// Called every frame
void UWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeapon::InitializeWeapon(struct FWeaponInfo WeaponInfo)
{
	_Info = WeaponInfo;
	_UpgradeState = FSaveManager::Get().GetWeaponUpgrades(WeaponInfo.ID);
	_bInitialized = true;
}

void UWeapon::Unlock()
{
	FSaveManager::Get().UnlockWeapon(_Info.ID);
}

void UWeapon::Upgrade(EWeaponUpgradeType WeaponUpgrade)
{
	_UpgradeState.Upgrade(WeaponUpgrade);
	FSaveManager::Get().UpgradeWeapon(_Info.ID, _UpgradeState);
}

FWeaponInfo UWeapon::GetInfo()
{
	return _Info;
}

void UWeapon::FirePressed()
{
	_bFiring = true;
	OnFirePressed();
}

void UWeapon::FireReleased()
{
	if (_bFiring)
	{
		_bFiring = false;
		OnFireReleased();
	}
}

void UWeapon::Reload()
{
	_bReloading = true;
	OnBeginReload();
}

float UWeapon::GetDamage()
{
	return _Info.GetDamage(_UpgradeState);
}

float UWeapon::GetArmorPenetration()
{
	return _Info.GetArmorPenetration(_UpgradeState);
}

float UWeapon::GetFireRate()
{
	return _Info.GetFireRate(_UpgradeState);
}

float UWeapon::GetMagazineSize()
{
	return _Info.GetMagazineSize(_UpgradeState);
}

float UWeapon::GetReloadTime()
{
	return _Info.GetReloadTime(_UpgradeState);
}

