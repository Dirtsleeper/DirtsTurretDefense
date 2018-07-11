// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayUtilLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "General/Core/Game/GameplayGameMode.h"
#include "General/Core/Game/GameplayPlayerController.h"
#include "HUD/Game/GameHUD.h"


AGameplayGameMode* UGameUtilLibrary::GetGameMode(UObject* WorldContextObject)
{
	return Cast<AGameplayGameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
}

AGameplayPlayerController* UGameUtilLibrary::GetPlayerController(UObject* WorldContextObject)
{
	return Cast<AGameplayPlayerController>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));
}

AGameHUD* UGameUtilLibrary::GetHUD(APlayerController* PlayerController)
{
	return Cast<AGameHUD>(PlayerController->GetHUD());
}
