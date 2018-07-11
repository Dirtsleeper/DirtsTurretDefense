// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "MainMenuUtilLibrary.h"
#include "HUD/Main/Attachments/Weapons/PrimaryWeaponEnum.h"
#include "HUD/Main/Attachments/Weapons/SecondaryWeaponEnum.h"
#include "HUD/Main/Attachments/Weapons/SpecialWeaponEnum.h"
#include "HUD/Main/Attachments/TurretAttachmentEnum.h"


#include "CoreMinimal.h"
#include "General/Core/DirtsTurretDefenseGameModeBase.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class DIRTSTURRETDEFENSE_API AMainMenuGameMode : public ADirtsTurretDefenseGameModeBase
{
	GENERATED_BODY()
	
private:

protected:

public:

public:
	void EquipPrimaryWeapon(EPrimaryWeapon Weapon);

	void EquipSecondaryWeapon(ESecondaryWeapon Weapon);

	void EquipSpecialWeapon(ESpecialWeapon Weapon);

	void EquipTurretAttachment(ETurretAttachment Attachment);

protected:

private:
	
	
};
