// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "DirtsTurretDefense.h"
#include "ImpactMaterialEnum.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UWeapon;

UCLASS()
class DIRTSTURRETDEFENSE_API AProjectile : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY()
	UStaticMeshComponent* _Mesh;

	UPROPERTY()
	class UParticleSystemComponent* _Trail;

	UPROPERTY()
	class UProjectileMovementComponent* _ProjectileMovement;

	UPROPERTY()
	UWeapon* _OwningWeapon;

protected:

public:

public:
	// Sets default values for this actor's properties
	AProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InitializeProjectile(UWeapon* OwningWeapon);

	UFUNCTION()
	virtual void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

	void TriggerHit(AActor* Target);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void DealDamage(AActor* HitActor, const FHitResult& Hit);

private:
	void SpawnImpactParticle(EImpactMaterial ImpactMaterial);
	
};
