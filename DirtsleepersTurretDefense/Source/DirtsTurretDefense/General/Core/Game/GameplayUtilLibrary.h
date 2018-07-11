// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "General/UtilLibrary.h"
#include "GameplayUtilLibrary.generated.h"

/**
 * 
 */

class AGameplayGameMode;
class AGameplayPlayerController;
class AGameHUD;

UCLASS()
class DIRTSTURRETDEFENSE_API UGameUtilLibrary : public UUtilLibrary
{
	GENERATED_BODY()
private:

protected:

public:

public:
	static AGameplayGameMode* GetGameMode(UObject* WorldContextObject);

	static AGameplayPlayerController* GetPlayerController(UObject* WorldContextObject);

	static AGameHUD* GetHUD(APlayerController* PlayerController);

protected:

private:
	
	
	
};
