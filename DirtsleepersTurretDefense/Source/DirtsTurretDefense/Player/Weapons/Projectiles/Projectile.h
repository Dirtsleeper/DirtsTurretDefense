// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ProjectileInfoStruct.h"
#include "DirtsTurretDefense.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

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

	FProjectileInfo _Info;

protected:

public:

public:
	// Sets default values for this actor's properties
	AProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void InitializeProjectile(FProjectileInfo Info);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);

private:
	void SpawnImpactParticle(EImpactMaterial ImpactMaterial);
	
};
