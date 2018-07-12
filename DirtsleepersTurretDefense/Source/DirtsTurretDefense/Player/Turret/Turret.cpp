// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "General/Core/TurretDefenseGameInstance.h"
#include "Player/Weapons/Weapon.h"

#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "TurretSave.h"


// Sets default values
ATurret::ATurret()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	RootComponent = m_BaseMesh;

	m_BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	m_BodyMesh->SetupAttachment(GetRootComponent());

	m_WeaponAttachPoint = CreateDefaultSubobject<USceneComponent>(TEXT("WeaponAttachPoint"));
	m_WeaponAttachPoint->SetupAttachment(m_BodyMesh);

	m_PrimaryWeaponLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PrimaryWeaponLeft"));
	m_PrimaryWeaponLeft->SetupAttachment(m_WeaponAttachPoint);

	m_PrimaryWeaponRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PrimaryWeaponRight"));
	m_PrimaryWeaponRight->SetupAttachment(m_WeaponAttachPoint);

	m_SecondaryWeaponLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondaryWeaponLeft"));
	m_SecondaryWeaponLeft->SetupAttachment(m_WeaponAttachPoint);

	m_SecondaryWeaponRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondaryWeaponRight"));
	m_SecondaryWeaponRight->SetupAttachment(m_WeaponAttachPoint);


	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_Camera->SetupAttachment(m_WeaponAttachPoint);
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

}

void ATurret::SwitchWeapons()
{
	if (_SelectedWeapon == _PrimaryWeapon)
	{
		SelectSecondaryWeapon();
	}
	else
	{
		SelectPrimaryWeapon();
	}
}

void ATurret::SelectPrimaryWeapon()
{
	if (_PrimaryWeapon)
	{
		_SelectedWeapon = _PrimaryWeapon;
	}
}

void ATurret::SelectSecondaryWeapon()
{
	if (_SecondaryWeapon)
	{
		_SelectedWeapon = _SecondaryWeapon;
	}
}

UWeapon* ATurret::GetSelectedWeapon()
{
	return _SelectedWeapon.Get();
}

void ATurret::InitializeWeapons()
{
	
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

