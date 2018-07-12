// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"


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
		UE_LOG(LogTemp, Error, TEXT("Initialize State needs called on %s before RegisterComponent"), *GetFName().ToString());
	}
}

void UWeapon::OnFirePressed()
{

}

void UWeapon::OnFireReleased()
{

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

// Called every frame
void UWeapon::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeapon::InitializeUpgrades(FWeaponUpgrade UpgradeState)
{
	_bInitialized = true;
}

void UWeapon::FirePressed()
{
	_bFiring = true;
	OnFirePressed();
}

void UWeapon::FireReleased()
{
	_bFiring = false;
	OnFireReleased();
}

void UWeapon::Reload()
{
	_bReloading = true;
	OnBeginReload();
}

