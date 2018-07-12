// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayPlayerController.h"

#include "GameFramework/Pawn.h"
#include "Player/Weapons/WeaponInterface.h"

void AGameplayPlayerController::Possess(APawn* NewPawn)
{
	Super::Possess(NewPawn);

	ControlledPawn = NewPawn;
}

void AGameplayPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AGameplayPlayerController::InputAction_Fire_Pressed);
	InputComponent->BindAction(TEXT("Fire"), IE_Released, this, &AGameplayPlayerController::InputAction_Fire_Released);
	InputComponent->BindAction(TEXT("Reload"), IE_Pressed, this, &AGameplayPlayerController::InputAction_Reload_Pressed);
	InputComponent->BindAction(TEXT("SwitchWeapons"), IE_Pressed, this, &AGameplayPlayerController::InputAction_SwitchWeapons_Pressed);
	InputComponent->BindAction(TEXT("SelectPrimaryWeapon"), IE_Pressed, this, &AGameplayPlayerController::InputAction_SelectPrimaryWeapon_Pressed);
	InputComponent->BindAction(TEXT("SelectSecondaryWeapon"), IE_Pressed, this, &AGameplayPlayerController::InputAction_SelectSecondaryWeapon_Pressed);
	InputComponent->BindAction(TEXT("FireSpecialWeapon"), IE_Pressed, this, &AGameplayPlayerController::InputAction_FireSpecialWeapon_Pressed);

}

void AGameplayPlayerController::InputAction_Fire_Pressed()
{
	if (IWeaponInterface* Interface = Cast<IWeaponInterface>(ControlledPawn))
	{
		Interface->FirePressed();
	}
}

void AGameplayPlayerController::InputAction_Fire_Released()
{
	if (IWeaponInterface* Interface = Cast<IWeaponInterface>(ControlledPawn))
	{
		Interface->FirePressed();
	}
}

void AGameplayPlayerController::InputAction_Reload_Pressed()
{
	if (IWeaponInterface* Interface = Cast<IWeaponInterface>(ControlledPawn))
	{
		Interface->FireReleased();
	}
}

void AGameplayPlayerController::InputAction_SwitchWeapons_Pressed()
{
	if (IWeaponInterface* Interface = Cast<IWeaponInterface>(ControlledPawn))
	{
		Interface->SwitchWeapons();
	}
}

void AGameplayPlayerController::InputAction_SelectPrimaryWeapon_Pressed()
{
	if (IWeaponInterface* Interface = Cast<IWeaponInterface>(ControlledPawn))
	{
		Interface->SelectPrimaryWeapon();
	}
}

void AGameplayPlayerController::InputAction_SelectSecondaryWeapon_Pressed()
{
	if (IWeaponInterface* Interface = Cast<IWeaponInterface>(ControlledPawn))
	{
		Interface->SelectSecondaryWeapon();
	}
}

void AGameplayPlayerController::InputAction_FireSpecialWeapon_Pressed()
{
	if (IWeaponInterface* Interface = Cast<IWeaponInterface>(ControlledPawn))
	{
		Interface->FireSpecialWeapon();
	}
}
