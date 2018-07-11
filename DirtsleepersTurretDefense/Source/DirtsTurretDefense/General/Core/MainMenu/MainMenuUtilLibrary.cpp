// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuUtilLibrary.h"

#include "Kismet/GameplayStatics.h"
#include "MainMenuGameMode.h"
#include "MainMenuPlayerController.h"
#include "HUD/Main/MainHUD.h"


AMainMenuGameMode* UMainMenuUtilLibrary::GetGameMode(UObject* WorldContextObject)
{
	return Cast<AMainMenuGameMode>(UGameplayStatics::GetGameMode(WorldContextObject));
}

AMainMenuPlayerController* UMainMenuUtilLibrary::GetPlayerController(UObject* WorldContextObject)
{
	return Cast<AMainMenuPlayerController>(UGameplayStatics::GetPlayerController(WorldContextObject, 0));
}

AMainHUD* UMainMenuUtilLibrary::GetHUD(APlayerController* PlayerController)
{
	return Cast<AMainHUD>(PlayerController->GetHUD());
}
