// Fill out your copyright notice in the Description page of Project Settings.

#include "CombatComponent.h"

#include "CombatInfoStruct.h"
#include "GameFramework/Character.h"
#include "General/Core/TurretDefenseGameInstance.h"
#include "General/Core/Game/Combat/CombatInterface.h"
#include "Combat/ShieldComponent.h"

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
	ExitCombat();
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

void UCombatComponent::EnterCombat()
{
	m_bInCombat = true;
	StopShieldRegen();
	GetWorld()->GetTimerManager().SetTimer(_CombatTimer, this, &UCombatComponent::ExitCombat, _ExitCombatDuration);
}

void UCombatComponent::ExitCombat()
{
	m_bInCombat = false;
	if (_Info->GetShield() && _Info->GetShieldRegen())
	{
		StartShieldRegen();
	}
}

void UCombatComponent::StartShieldRegen()
{
	Cast<ICombatInterface>(GetOwner())->GetShieldComponent()->Enable();
	RegenShieldTick();
	GetWorld()->GetTimerManager().SetTimer(_ShieldRegenTimer, this, &UCombatComponent::RegenShieldTick, 1.f, true);
}

void UCombatComponent::StopShieldRegen()
{
	GetWorld()->GetTimerManager().ClearTimer(_ShieldRegenTimer);
}

void UCombatComponent::RegenShieldTick()
{
	if (!IsDead())
	{
		_ShieldRemaining = FMath::Min(_ShieldRemaining + _Info->GetShieldRegen(), _Info->GetShield());
	}
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

void UCombatComponent::TakeDamage(const FDamageInfo& DamageInfo)
{
	EnterCombat();

	if (_ShieldRemaining > 0)
	{
		_ShieldRemaining -= DamageInfo.Damage;
		if (_ShieldRemaining <= 0)
		{
			Cast<ICombatInterface>(GetOwner())->GetShieldComponent()->Disable();
			_ShieldRemaining = 0;
			_CurrentHealth -= CalculateDamage(-_ShieldRemaining, DamageInfo.ArmorPenetration);
		}
		if (DamageInfo.bDirectHit)
		{
			Cast<ICombatInterface>(GetOwner())->GetShieldComponent()->Impact(DamageInfo.HitInfo.ImpactPoint);
		}
	}
	else
	{
		_CurrentHealth -= CalculateDamage(DamageInfo.Damage, DamageInfo.ArmorPenetration);
	}
	if (_CurrentHealth <= 0)
	{
		Death(DamageInfo.Instigator);
	}
}

bool UCombatComponent::IsInCombat()
{
	return m_bInCombat;
}

bool UCombatComponent::IsDead()
{
	return _CurrentHealth <= 0;
}

float UCombatComponent::GetShieldPercent()
{
	return _ShieldRemaining / _Info->GetShield();
}

