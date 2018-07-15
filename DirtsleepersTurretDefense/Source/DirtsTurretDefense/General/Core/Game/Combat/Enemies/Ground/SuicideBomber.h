// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "General/Core/Game/Combat/CombatInterface.h"
#include "Player/Weapons/WeaponInterface.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SuicideBomber.generated.h"

UCLASS()
class DIRTSTURRETDEFENSE_API ASuicideBomber : public ACharacter, public ICombatInterface, public IWeaponInterface
{
	GENERATED_BODY()
private:
	UPROPERTY()
	class UCombatComponent* _CombatComponent;

	UPROPERTY()
	class UWeapon* _Weapon;

protected:

public:

public:
	// Sets default values for this character's properties
	ASuicideBomber();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Combat Interface
	virtual FText GetEnemyName() override;

	virtual void PossessedBy(AController* NewController) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual UWeapon* GetSelectedWeapon() override;

	virtual void OnDeath(AActor* Source) override;

private:
	
};
