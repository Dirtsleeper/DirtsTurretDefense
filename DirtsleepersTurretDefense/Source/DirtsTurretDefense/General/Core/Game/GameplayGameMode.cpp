// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayGameMode.h"

#include "HUD/Game/GameHUD.h"
#include "GameplayPlayerController.h"


AGameplayGameMode::AGameplayGameMode() : Super()
{
	PlayerControllerClass = AGameplayPlayerController::StaticClass();
	HUDClass = AGameHUD::StaticClass();
}
