// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"

#include "Engine/World.h"
#include "TimerManager.h"
#include "Projectiles/Projectile.h"
#include "WeaponInfoStruct.h"

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
	if (!_bReloading && !IsFireTimerActive())
	{
		FireProjectile();
	}
}

void UWeapon::OnFireReleased()
{
	
}

void UWeapon::FireProjectile()
{
	if (_bFiring)
	{
		FTransform SpawnTransform = FTransform();
		SpawnTransform.SetLocation(GetOwner()->GetActorLocation() + FVector(0, 0, 100) + GetOwner()->GetActorForwardVector() * 200);
		SpawnTransform.SetRotation(GetOwner()->GetActorRotation().Quaternion());
		SpawnTransform.SetScale3D(FVector(10));
		AProjectile* Projectile = GetWorld()->SpawnActorDeferred<AProjectile>(AProjectile::StaticClass(), SpawnTransform, GetOwner());
		Projectile->InitializeProjectile(_Info->GetProjectileInfo());
		Projectile->FinishSpawning(SpawnTransform);
		StartFireTimer();
	}
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
	GetWorld()->GetTimerManager().SetTimer(FireProjectileTimer, this, &UWeapon::FireProjectile, _Info->GetTimeBetweenProjectiles(_UpgradeState), false);
}

void UWeapon::ClearFireTimer()
{
	GetWorld()->GetTimerManager().ClearTimer(FireProjectileTimer);
}

bool UWeapon::IsFireTimerActive()
{
	return GetWorld()->GetTimerManager().IsTimerActive(FireProjectileTimer);
}

// Called every frame
void UWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeapon::InitializeWeapon(FWeaponInfo* WeaponInfo)
{
	_Info = WeaponInfo;
	_UpgradeState = FSaveManager::Get().GetWeaponUpgrades(_Info->ID);
	_bInitialized = true;
}

void UWeapon::Unlock()
{
	FSaveManager::Get().UnlockWeapon(_Info->ID);
}

void UWeapon::Upgrade(EWeaponUpgradeType WeaponUpgrade)
{
	_UpgradeState.Upgrade(WeaponUpgrade);
	FSaveManager::Get().UpgradeWeapon(_Info->ID, _UpgradeState);
}

TSharedPtr<FWeaponInfo> UWeapon::GetInfo()
{
	TSharedPtr<FWeaponInfo> SharedPtr(new FWeaponInfo(*_Info));
	return SharedPtr;
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
	return _Info->GetDamage(_UpgradeState);
}

float UWeapon::GetArmorPenetration()
{
	return _Info->GetArmorPenetration(_UpgradeState);
}

float UWeapon::GetFireRate()
{
	return _Info->GetFireRate(_UpgradeState);
}

float UWeapon::GetMagazineSize()
{
	return _Info->GetMagazineSize(_UpgradeState);
}

float UWeapon::GetReloadTime()
{
	return _Info->GetReloadTime(_UpgradeState);
}

