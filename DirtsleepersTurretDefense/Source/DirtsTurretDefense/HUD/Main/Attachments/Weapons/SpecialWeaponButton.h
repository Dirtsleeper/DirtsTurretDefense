// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "SpecialWeaponEnum.h"

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "SpecialWeaponButton.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API USpecialWeaponButton : public UButton
{
	GENERATED_BODY()

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnButtonPressedSignature, ESpecialWeapon, Weapon);

private:
	ESpecialWeapon _Weapon;

protected:

public:
	UPROPERTY(BlueprintAssignable)
	FOnButtonPressedSignature OnPressed_Custom;

public:
	void SetWeapon(ESpecialWeapon Weapon);

protected:

private:
	UFUNCTION()
	void Pressed();
};
