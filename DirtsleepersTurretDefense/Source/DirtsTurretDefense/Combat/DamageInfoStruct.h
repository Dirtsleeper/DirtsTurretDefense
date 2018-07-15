// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Engine/EngineTypes.h"

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "DamageInfoStruct.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FDamageInfo
{
	GENERATED_BODY()
private:

protected:

public:
	AActor* Instigator;

	float Damage;

	float ArmorPenetration;

	bool bDirectHit = false;

	FHitResult HitInfo;

public:
	FDamageInfo() {}

	FDamageInfo(AActor* instigator, float damage, float armorPenetration, bool directHit = false, const FHitResult& hitInfo = FHitResult())
	{
		Instigator = instigator;
		Damage = damage;
		ArmorPenetration = armorPenetration;
		bDirectHit = directHit;
		HitInfo = hitInfo;
	}

protected:

private:

};

UCLASS()
class DIRTSTURRETDEFENSE_API UDamageInfoStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
	
	
	
	
};
