// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Player/Weapons/WeaponInterface.h"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Turret.generated.h"

class UStaticMeshComponent;

UCLASS(Abstract)
class DIRTSTURRETDEFENSE_API ATurret : public APawn, public IWeaponInterface
{
	GENERATED_BODY()

private:
	// Weapons
	UPROPERTY()
	UWeapon* _PrimaryWeapon;

	UPROPERTY()
	UWeapon* _SecondaryWeapon;

	UPROPERTY()
	UWeapon* _SpecialWeapon;

	UPROPERTY()
	TWeakObjectPtr<UWeapon> _SelectedWeapon;

	UPROPERTY()
	class UTurretSave* _PlayerTurretSave;

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* m_BaseMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* m_BodyPivotMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* m_BodyMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* m_PrimaryWeapon;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* m_SecondaryWeaponLeft;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* m_SecondaryWeaponRight;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	class UCameraComponent* m_Camera;

public:

public:
	// Sets default values for this pawn's properties
	ATurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UWeapon* GetPrimaryWeapon();

	UWeapon* GetSecondaryWeapon();

	UWeapon* GetSpecialWeapon();

	// Weapon Interface
	virtual void IntializeWeapons(UWeapon*& PrimaryWeapon, UWeapon*& SecondaryWeapon, UWeapon*& SpecialWeapon) override;

	virtual UWeapon* GetSelectedWeapon() override;

	FVector GetForward();

	FRotator GetRotation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void LookUp(float AxisValue);

	virtual void LookRight(float AxisValue);

	// Weapon Interface
	virtual void SwitchWeapons() override;

	virtual void SelectPrimaryWeapon() override;

	virtual void SelectSecondaryWeapon() override;

};
