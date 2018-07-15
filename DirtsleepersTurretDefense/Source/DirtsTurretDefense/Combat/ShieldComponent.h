// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "ShieldComponent.generated.h"

/**
 * 
 */
UCLASS()
class DIRTSTURRETDEFENSE_API UShieldComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
private:
	TArray<int32> _AvailableIndices;

	TArray<int32> _IndicesInUse;

	TMap<int32, float> _IndexLifeTime;

	TMap<int32, float> _BaseRadius;

	int32 _LastIndexUsed;

	UPROPERTY()
	class UCurveFloat* _RadiusCurve;

	UPROPERTY()
	class UCombatComponent* _CombatComponent;

	UPROPERTY()
	class UMaterialInterface* _Material;

	UPROPERTY()
	class UMaterialInstanceDynamic* _DynamicMaterial;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 m_NumberOfPossibleImpacts = 10;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float m_ImpactLifetime = 1.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool m_bOverrideDesign = false;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (EditCondition = m_bOverrideDesign))
	UTexture* m_DesignTexture;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	/**
	* Smaller number is larger design.
	*/
	float m_DesignSize = 7.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FLinearColor m_Color1 = FLinearColor(0, 2, 45);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FLinearColor m_Color2 = FLinearColor(1, 1, 1);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	class UParticleSystem* m_ImpactParticle;

public:

public:
	UShieldComponent();

	void Impact(FVector Location, float Radius = 50.f);

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction);

	virtual void OnRegister() override;

	void Enable();

	void Disable();

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	void InitializeImpactArray();

	int32 GetIndex();
	
	void UseIndex(int32 Index);

	void FinishUsingIndex(int32 Index);

	void UpdateImpacts(float DeltaTime);
	
};
