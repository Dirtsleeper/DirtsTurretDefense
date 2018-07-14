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
	UStaticMeshComponent* m_BodyMesh;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	USceneComponent* m_WeaponAttachPoint;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* m_PrimaryWeaponLeft;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly)
	UStaticMeshComponent* m_PrimaryWeaponRight;

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

	virtual UWeapon* GetSelectedWeapon() override;

	UWeapon* GetPrimaryWeapon();

	UWeapon* GetSecondaryWeapon();

	UWeapon* GetSpecialWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	// Weapon Interface
	void SwitchWeapons();

	void SelectPrimaryWeapon();

	void SelectSecondaryWeapon();

};
