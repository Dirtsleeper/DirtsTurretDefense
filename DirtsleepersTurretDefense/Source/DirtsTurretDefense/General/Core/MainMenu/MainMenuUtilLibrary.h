// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/UtilLibrary.h"
#include "MainMenuUtilLibrary.generated.h"

/**
 * 
 */

class AMainMenuGameMode;
class AMainMenuPlayerController;
class AMainHUD;

UCLASS()
class DIRTSTURRETDEFENSE_API UMainMenuUtilLibrary : public UUtilLibrary
{
	GENERATED_BODY()
private:

protected:

public:

public:
	static AMainMenuGameMode* GetGameMode(UObject* WorldContextObject);

	static AMainMenuPlayerController* GetPlayerController(UObject* WorldContextObject);

	static AMainHUD* GetHUD(APlayerController* PlayerController);

protected:

private:
	
	
	
};
