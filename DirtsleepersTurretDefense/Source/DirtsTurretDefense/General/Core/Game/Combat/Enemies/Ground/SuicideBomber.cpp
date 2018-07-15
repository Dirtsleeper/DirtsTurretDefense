// Fill out your copyright notice in the Description page of Project Settings.

#include "SuicideBomber.h"

#include "General/Core/Game/Combat/CombatComponent.h"
#include "Player/Weapons/Weapon.h"


// Sets default values
ASuicideBomber::ASuicideBomber()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_CombatComponent = CreateDefaultSubobject<UCombatComponent>(TEXT("CombatComponent"));
	AddOwnedComponent(_CombatComponent);
}

// Called when the game starts or when spawned
void ASuicideBomber::BeginPlay()
{
	Super::BeginPlay();

	IntializeWeapons(_Weapon, _Weapon, _Weapon);

	OnBeginPlay();
}

UWeapon* ASuicideBomber::GetSelectedWeapon()
{
	return _Weapon;
}

void ASuicideBomber::OnDeath(AActor* Source)
{
	if (Source != this)
	{
		FirePressed();
	}
}

// Called every frame
void ASuicideBomber::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASuicideBomber::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

FText ASuicideBomber::GetEnemyName()
{
	return FText::FromString(TEXT("Suicide Bomber"));
}

void ASuicideBomber::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	OnPossessed(NewController);
}

