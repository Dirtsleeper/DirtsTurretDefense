// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GamemodeEnum.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TurretDefenseGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UTurretDefenseGameInstance : public UGameInstance
{
	GENERATED_BODY()
private:

protected:
	EGamemode m_SelectedGamemode = EGamemode::GM_Default;

public:

public:
	virtual void Init() override;

	void SetSelectedGamemode(EGamemode NewGamemode);

protected:

private:

};
