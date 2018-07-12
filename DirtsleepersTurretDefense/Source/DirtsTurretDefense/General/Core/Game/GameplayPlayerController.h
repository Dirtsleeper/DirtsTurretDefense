// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/Core/TD_PlayerController.h"
#include "GameplayPlayerController.generated.h"

/**
 * 
 */

class APawn;

UCLASS()
class DIRTSTURRETDEFENSE_API AGameplayPlayerController : public ATD_PlayerController
{
	GENERATED_BODY()
	
private:

protected:
	UPROPERTY()
	APawn* ControlledPawn;

public:

public:
	virtual void Possess(APawn* NewPawn) override;

protected:
	virtual void SetupInputComponent() override;

	void InputAction_Fire_Pressed();

	void InputAction_Fire_Released();

	void InputAction_Reload_Pressed();

	void InputAction_SwitchWeapons_Pressed();

	void InputAction_SelectPrimaryWeapon_Pressed();

	void InputAction_SelectSecondaryWeapon_Pressed();

	void InputAction_FireSpecialWeapon_Pressed();

private:
	
	
};
