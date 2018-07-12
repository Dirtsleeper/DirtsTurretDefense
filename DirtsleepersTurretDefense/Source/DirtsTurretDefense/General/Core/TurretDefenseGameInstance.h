// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GamemodeEnum.h"
#include "Kismet/GameplayStatics.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TurretDefenseGameInstance.generated.h"

/**
 * 
 */

class UTurretDefenseGameInstance;

typedef UTurretDefenseGameInstance GI;

UCLASS()
class DIRTSTURRETDEFENSE_API UTurretDefenseGameInstance : public UGameInstance
{
	GENERATED_BODY()
private:
	int32 _CurrentSaveSlot = 0;

protected:
	EGamemode m_SelectedGamemode = EGamemode::GM_Default;

public:

public:
	static FORCEINLINE UTurretDefenseGameInstance* GetGameInstance(UObject* WorldContextObject)
	{
		return Cast<UTurretDefenseGameInstance>(UGameplayStatics::GetGameInstance(WorldContextObject));
	}

	virtual void Init() override;

	void SetSelectedGamemode(EGamemode NewGamemode);

	void SetSaveSlot(int32 Slot);

	int32 GetSaveSlot();

protected:

private:

};
