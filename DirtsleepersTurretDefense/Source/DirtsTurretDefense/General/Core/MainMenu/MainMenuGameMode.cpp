// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuGameMode.h"


void AMainMenuGameMode::EquipPrimaryWeapon(EPrimaryWeapon Weapon)
{
	UE_LOG(LogTemp, Error, TEXT("Primary Weapon Equipped"));
}

void AMainMenuGameMode::EquipSecondaryWeapon(ESecondaryWeapon Weapon)
{
	UE_LOG(LogTemp, Error, TEXT("Secondary Weapon Equipped"));
}

void AMainMenuGameMode::EquipSpecialWeapon(ESpecialWeapon Weapon)
{
	UE_LOG(LogTemp, Error, TEXT("Special Weapon Equipped"));
}

void AMainMenuGameMode::EquipTurretAttachment(ETurretAttachment Attachment)
{
	UE_LOG(LogTemp, Error, TEXT("Turret Attachment Equipped"));
}
