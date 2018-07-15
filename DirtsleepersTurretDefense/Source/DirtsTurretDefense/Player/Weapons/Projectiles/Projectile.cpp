// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"

#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Player/Weapons/Weapon.h"
#include "Player/Weapons/WeaponInfoStruct.h"
#include "GameFramework/Pawn.h"
#include "General/Core/Game/Combat/CombatInterface.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	_Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = _Mesh;

	_Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	_Mesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	_Mesh->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	_Mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);

	_Trail = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Trail"));
	_Trail->SetupAttachment(GetRootComponent());

	_ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	_ProjectileMovement->bInitialVelocityInLocalSpace = true;
	_ProjectileMovement->bRotationFollowsVelocity = true;
	AddOwnedComponent(_ProjectileMovement);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();

	OnActorHit.AddDynamic(this, &AProjectile::OnHit);

	SetLifeSpan(20.f);
}

void AProjectile::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	SpawnImpactParticle(EImpactMaterial::Terrain);
	DealDamage(OtherActor);
	Destroy();
}

void AProjectile::DealDamage(AActor* HitActor)
{
	float Radius = UUtilLibrary::FT2CM(_OwningWeapon->GetInfo()->GetProjectileInfo().DamageRadius);
	if (Radius > 0)
	{
		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(EObjectTypeQuery::ObjectTypeQuery3);
		TArray<AActor*> OutActors;
		UKismetSystemLibrary::SphereOverlapActors(this, GetActorLocation(), Radius, ObjectTypes, APawn::StaticClass(), TArray<AActor*>(), OutActors);

		for (AActor* Actor : OutActors)
		{
			if (ICombatInterface* Interface = Cast<ICombatInterface>(Actor))
			{
				Interface->TakeDamage(GetOwner(), _OwningWeapon->GetDamage(), _OwningWeapon->GetArmorPenetration());
			}
		}
	}
	else
	{
		if (ICombatInterface* Interface = Cast<ICombatInterface>(HitActor))
		{
			Interface->TakeDamage(GetOwner(), _OwningWeapon->GetDamage(), _OwningWeapon->GetArmorPenetration());
		}
	}
}

void AProjectile::SpawnImpactParticle(EImpactMaterial ImpactMaterial)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), _OwningWeapon->GetInfo()->GetProjectileInfo().GetImpactParticle(ImpactMaterial), GetActorTransform());
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::InitializeProjectile(UWeapon* OwningWeapon)
{
	_OwningWeapon = OwningWeapon;
	_Mesh->SetStaticMesh(_OwningWeapon->GetInfo()->GetProjectileInfo().Mesh);
	_Trail->SetTemplate(_OwningWeapon->GetInfo()->GetProjectileInfo().Trail);
	_ProjectileMovement->InitialSpeed = _ProjectileMovement->MaxSpeed = UUtilLibrary::FT2CM(_OwningWeapon->GetInfo()->GetProjectileInfo().Velocity);
	_ProjectileMovement->Velocity = FVector(1, 0, 0);
}

void AProjectile::TriggerHit(AActor* Target)
{
	OnHit(this, Target, FVector(), FHitResult());
}
