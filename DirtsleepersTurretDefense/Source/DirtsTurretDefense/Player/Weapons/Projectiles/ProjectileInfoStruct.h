// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ImpactMaterialEnum.h"

#include "CoreMinimal.h"
#include "Engine/UserDefinedStruct.h"
#include "ProjectileInfoStruct.generated.h"

/**
 * 
 */

class UParticleSystem;

USTRUCT(BlueprintType)
struct FProjectileInfo
{
	GENERATED_BODY()
private:

protected:

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UStaticMesh* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	/**
	* FPS
	*/
	float Velocity = 1200.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	/**
	* Radius in Feet
	*/
	float DamageRadius = 0.f;

	UPROPERTY(Category = "Emitters", EditAnywhere, BlueprintReadOnly)
	UParticleSystem* Trail;

	UPROPERTY(Category = "Emitters", EditAnywhere, BlueprintReadOnly)
	UParticleSystem* Impact_Terrain;

	UPROPERTY(Category = "Emitters", EditAnywhere, BlueprintReadOnly)
	UParticleSystem* Impact_Body;

	UPROPERTY(Category = "Emitters", EditAnywhere, BlueprintReadOnly)
	UParticleSystem* Impact_Metal;

public:
	UParticleSystem* GetImpactParticle(EImpactMaterial Material);

protected:

private:

};

UCLASS()
class DIRTSTURRETDEFENSE_API UProjectileInfoStruct : public UUserDefinedStruct
{
	GENERATED_BODY()
	
	
	
	
};
