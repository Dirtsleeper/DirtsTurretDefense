// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PrimaryWeaponEnum.h"

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "PrimaryWeaponButton.generated.h"

/**
 * 
 */

UCLASS()
class DIRTSTURRETDEFENSE_API UPrimaryWeaponButton : public UButton
{
	GENERATED_BODY()

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonPressedSignature, EPrimaryWeapon, Weapon);

private:
	EPrimaryWeapon _Weapon;

protected:

public:
	UPROPERTY(BlueprintAssignable)
	FOnButtonPressedSignature OnPressed_Custom;

public:
	void SetWeapon(EPrimaryWeapon Weapon);

protected:

private:
	UFUNCTION()
	void Pressed();
	
};
