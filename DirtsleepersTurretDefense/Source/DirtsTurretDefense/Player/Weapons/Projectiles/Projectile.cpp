// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"

#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

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
	AddOwnedComponent(_ProjectileMovement);

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddDynamic(this, &AProjectile::OnHit);
}

void AProjectile::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	SpawnImpactParticle(EImpactMaterial::Terrain);
	Destroy();
}

void AProjectile::SpawnImpactParticle(EImpactMaterial ImpactMaterial)
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), _Info.GetImpactParticle(ImpactMaterial), GetActorTransform());
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::InitializeProjectile(FProjectileInfo Info)
{
	_Info = Info;
	if (_Info.Mesh)
	{
		_Mesh->SetStaticMesh(_Info.Mesh);
	}
	if (_Info.Trail)
	{
		_Trail->SetTemplate(_Info.Trail);
	}
	_ProjectileMovement->InitialSpeed = _ProjectileMovement->MaxSpeed = UUtilLibrary::FT2CM(_Info.Velocity);
	_ProjectileMovement->Velocity = FVector(1, 0, 0);
}

