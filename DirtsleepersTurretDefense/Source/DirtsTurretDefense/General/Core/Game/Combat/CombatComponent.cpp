// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatComponent.h"

#include "CombatInfoStruct.h"
#include "GameFramework/Character.h"
#include "General/Core/TurretDefenseGameInstance.h"
#include "General/Core/Game/Combat/CombatInterface.h"

// Sets default values for this component's properties
UCombatComponent::UCombatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeStats();
}

float UCombatComponent::CalculateDamage(float Damage, float ArmorPenetration)
{
	float Armor = FMath::Max(_Info->GetArmor() - ArmorPenetration, 0.f);
	Damage -= Armor;
	return FMath::Max(Damage, 0.f);
}

void UCombatComponent::Death(AActor* Source)
{
	Cast<ICombatInterface>(GetOwner())->OnDeath(Source);
	GetOwner()->Destroy();
}

void UCombatComponent::InitializeStats()
{
	_Info = GI::GetGameInstance(this)->GetCombatInfoFromDataTable(GetOwner());

	_CurrentHealth = _Info->GetHealth();

	_ShieldRemaining = _Info->GetShield();
}

// Called every frame
void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCombatComponent::TakeDamage(AActor* Source, float Damage, float ArmorPenetration)
{
	if (_ShieldRemaining)
	{
		_ShieldRemaining -= Damage;
		if (_ShieldRemaining < 0)
		{
			_CurrentHealth -= CalculateDamage(-_ShieldRemaining, ArmorPenetration);
		}
	}
	else
	{
		_CurrentHealth -= CalculateDamage(Damage, ArmorPenetration);
	}
	if (_CurrentHealth <= 0)
	{
		Death(Source);
	}
}

