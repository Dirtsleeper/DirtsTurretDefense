// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "WeaponUnlockSave.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UWeaponUnlockSave : public USaveGame
{
	GENERATED_BODY()
private:
	TSet<int32> _UnlockedWeapons;

protected:

public:

public:
	void UnlockWeapon(int32 WeaponID);

	bool IsWeaponUnlocked(int32 WeaponID);

protected:

private:
	
	
	
};
