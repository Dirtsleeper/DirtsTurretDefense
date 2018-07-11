// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "PrimaryWeaponEnum.h"

#include "CoreMinimal.h"
#include "HUD/Main/BaseWidgets/DropDownMenuChild.h"
#include "PrimaryWeaponSelectionWidget.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UPrimaryWeaponSelectionWidget : public UDropdownMenuChild
{
	GENERATED_BODY()
private:

protected:

public:

public:
	virtual void NativePreConstruct() override;

protected:

private:
	UFUNCTION()
	void EquipWeapon(EPrimaryWeapon Weapon);
	
};
