// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/DataTable.h"

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "WeaponSeconadryInfoStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FWeaponSeconadryInfo: public FTableRowBase
{
	GENERATED_BODY()
private:

protected:

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BaseDamage = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BaseAmorPenetration = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float FireRate = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MagazineSize = 20.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float ReloadTime = 2.5f;

public:

protected:

private:
};

UCLASS()
class DIRTSTURRETDEFENSE_API UWeaponInfoStruct: public UUserDefinedStruct
{
	GENERATED_BODY()
	
	
	
	
};
