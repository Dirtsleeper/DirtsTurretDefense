// Fill out your copyright notice in the Description page of Project Settings.

#include "Turret.h"
#include "General/Core/TurretDefenseGameInstance.h"
#include "Player/Weapons/Weapon.h"

#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "TurretSave.h"
#include "Player/Weapons/WeaponInfoStruct.h"


// Sets default values
ATurret::ATurret()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	RootComponent = m_BaseMesh;

	m_BodyPivotMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyPivot"));
	m_BodyPivotMesh->SetupAttachment(GetRootComponent());

	m_BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	m_BodyMesh->SetupAttachment(m_BodyPivotMesh);

	m_PrimaryWeapon = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PrimaryWeapon"));
	m_PrimaryWeapon->SetupAttachment(m_BodyMesh);

	m_SecondaryWeaponLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondaryWeaponLeft"));
	m_SecondaryWeaponLeft->SetupAttachment(m_BodyMesh);

	m_SecondaryWeaponRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SecondaryWeaponRight"));
	m_SecondaryWeaponRight->SetupAttachment(m_BodyMesh);

	m_Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	m_Camera->SetupAttachment(m_BodyMesh);
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();

	FSaveManager::Get().UnlockWeapon(0);

	IntializeWeapons(_PrimaryWeapon, _SecondaryWeapon, _SpecialWeapon);
	SelectPrimaryWeapon();
}

void ATurret::LookUp(float AxisValue)
{
	if (m_BodyMesh)
	{
		FRotator Rotation = m_BodyMesh->GetComponentRotation();
		Rotation += FRotator(AxisValue, 0.f, 0.f);
		FRotator ClampedRotation = FRotator(FMath::ClampAngle(Rotation.Pitch, -45.f, 90.f), 0.f, 0.f);
		m_BodyMesh->SetRelativeRotation(ClampedRotation);
	}
}

void ATurret::LookRight(float AxisValue)
{
	if (m_BodyMesh)
	{
		m_BodyMesh->AddLocalRotation(FRotator(0.f, AxisValue, 0.f));
	}
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

UWeapon* ATurret::GetPrimaryWeapon()
{
	return _PrimaryWeapon;
}

UWeapon* ATurret::GetSecondaryWeapon()
{
	return _SecondaryWeapon;
}

UWeapon* ATurret::GetSpecialWeapon()
{
	return _SpecialWeapon;
}

void ATurret::IntializeWeapons(UWeapon*& PrimaryWeapon, UWeapon*& SecondaryWeapon, UWeapon*& SpecialWeapon)
{
	if (UTurretSave* PlayerTurretSave = FSaveManager::Get().GetTurretSave())
	{
		if (PlayerTurretSave->PrimaryWeaponID != -1)
		{
			FWeaponInfo* Info = GI::GetGameInstance(this)->GetWeaponInfoFromDataTable(EWeaponType::Primary, PlayerTurretSave->PrimaryWeaponID);
			PrimaryWeapon = NewObject<UWeapon>(this, Info->WeaponClass, FName(*Info->Name.ToString()));
			PrimaryWeapon->InitializeWeapon(Info);
			PrimaryWeapon->RegisterComponent();
			AddOwnedComponent(PrimaryWeapon);
		}
		if (PlayerTurretSave->SecondaryWeaponID != -1)
		{
			FWeaponInfo* Info = GI::GetGameInstance(this)->GetWeaponInfoFromDataTable(EWeaponType::Secondary, PlayerTurretSave->SecondaryWeaponID);
			SecondaryWeapon = NewObject<UWeapon>(this, Info->WeaponClass, FName(*Info->Name.ToString()));
			SecondaryWeapon->InitializeWeapon(Info);
			SecondaryWeapon->RegisterComponent();
			AddOwnedComponent(SecondaryWeapon);
		}
		if (PlayerTurretSave->SpecialWeaponID != -1)
		{
			FWeaponInfo* Info = GI::GetGameInstance(this)->GetWeaponInfoFromDataTable(EWeaponType::Special, PlayerTurretSave->SpecialWeaponID);
			SpecialWeapon = NewObject<UWeapon>(this, Info->WeaponClass, FName(*Info->Name.ToString()));
			SpecialWeapon->InitializeWeapon(Info);
			SpecialWeapon->RegisterComponent();
			AddOwnedComponent(SpecialWeapon);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to find Player Turret Save."));
	}
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

	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ATurret::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &ATurret::LookRight);
}

UWeapon* ATurret::GetSelectedWeapon()
{
	return _SelectedWeapon.Get();
}

FVector ATurret::GetForward()
{
	return m_BodyMesh->GetForwardVector();
}

FRotator ATurret::GetRotation()
{
	return m_BodyMesh->GetComponentRotation();
}
