// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CombatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DIRTSTURRETDEFENSE_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	float _CurrentHealth = 100.f;
	
	float _ShieldRemaining = 0.f;

	struct FCombatInfo* _Info;

protected:

public:

public:
	// Sets default values for this component's properties
	UCombatComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void TakeDamage(AActor* Source, float Damage, float ArmorPenetration);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	float CalculateDamage(float Damage, float ArmorPenetration);

	void Death(AActor* Source);

private:
	void InitializeStats();
	
};
