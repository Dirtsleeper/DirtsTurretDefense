// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SecondaryWeaponEnum.h"

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "SecondaryWeaponButton.generated.h"

/**
 * 
 */

UCLASS()
class DIRTSTURRETDEFENSE_API USecondaryWeaponButton : public UButton
{
	GENERATED_BODY()

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonPressedSignature, ESecondaryWeapon, Weapon);

private:
	ESecondaryWeapon _Weapon;

protected:

public:
	UPROPERTY(BlueprintAssignable)
	FOnButtonPressedSignature OnPressed_Custom;

public:
	void SetWeapon(ESecondaryWeapon Weapon);

protected:

private:
	UFUNCTION()
	void Pressed();
};
