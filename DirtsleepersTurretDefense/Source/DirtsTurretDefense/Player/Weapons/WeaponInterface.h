// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Weapon.h"
#include "GameFramework/Actor.h"

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "WeaponInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UWeaponInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DIRTSTURRETDEFENSE_API IWeaponInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void IntializeWeapons(UWeapon*& PrimaryWeapon, UWeapon*& SecondaryWeapon, UWeapon*& SpecialWeapon);

	virtual void FirePressed();

	virtual void FireReleased();

	virtual void FireSpecialWeapon();

	virtual void Reload();

	virtual void SwitchWeapons();

	virtual void SelectPrimaryWeapon();

	virtual void SelectSecondaryWeapon();

	virtual	UWeapon* GetSelectedWeapon();
	
private:
	AActor* GetOwner();
	
};
