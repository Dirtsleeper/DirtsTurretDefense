// Fill out your copyright notice in the Description page of Project Settings.

#include "ShieldComponent.h"

#include "General/Core/Game/Combat/CombatInterface.h"
#include "General/Core/Game/Combat/CombatComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInterface.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/StaticMesh.h"
#include "Player/Weapons/Projectiles/Projectile.h"


UShieldComponent::UShieldComponent()
{
	ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialFinder(TEXT("Material'/Game/General/Combat/M_Shield.M_Shield'"));
	if (MaterialFinder.Succeeded())
	{
		_Material = MaterialFinder.Object;
	}

	ConstructorHelpers::FObjectFinder<UCurveFloat> CurveFinder(TEXT("CurveFloat'/Game/ArtAssets/2D/ShieldImpactCurve.ShieldImpactCurve'"));
	if (CurveFinder.Succeeded())
	{
		_RadiusCurve = CurveFinder.Object;
	}

	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

void UShieldComponent::Impact(FVector Location, float Radius)
{
	if (m_ImpactParticle)
	{
		FTransform SpawnTransform;
		SpawnTransform.SetLocation(Location);
		SpawnTransform.SetRotation((Location - GetComponentLocation()).Rotation().Quaternion());
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), m_ImpactParticle, SpawnTransform);
	}

	int32 Index = GetIndex();
	_BaseRadius[Index] = Radius;
	FString Index_Str = FString::FromInt(Index);
	FString ImpactParam(TEXT("Impact_"));
	ImpactParam += Index_Str;
	FString RadiusParam(TEXT("Radius_"));
	RadiusParam += Index_Str;
	_DynamicMaterial->SetVectorParameterValue(FName(*ImpactParam), FLinearColor(Location));
	_DynamicMaterial->SetScalarParameterValue(FName(*RadiusParam), Radius);
	
	_DynamicMaterial->SetScalarParameterValue(TEXT("ShieldPercent"), _CombatComponent->GetShieldPercent());
}

void UShieldComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateImpacts(DeltaTime);
}

void UShieldComponent::OnRegister()
{
	Super::OnRegister();

	if (GetStaticMesh())
	{
		SetMaterial(0, _Material);
	}
}

void UShieldComponent::Enable()
{
	SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
}

void UShieldComponent::Disable()
{
	SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void UShieldComponent::BeginPlay()
{
	Super::BeginPlay();

	SetComponentTickEnabled(true);

	_CombatComponent = Cast<ICombatInterface>(GetOwner())->GetCombatComponent();

	OnComponentBeginOverlap.AddDynamic(this, &UShieldComponent::OnOverlap);

	InitializeImpactArray();

	_DynamicMaterial = CreateDynamicMaterialInstance(0);
	if (m_bOverrideDesign)
	{
		_DynamicMaterial->SetTextureParameterValue(TEXT("DesignTex"), m_DesignTexture);
	}
	_DynamicMaterial->SetScalarParameterValue(TEXT("DesignSize"), m_DesignSize);

	_DynamicMaterial->SetVectorParameterValue(TEXT("Color1"), m_Color1);
	_DynamicMaterial->SetVectorParameterValue(TEXT("Color2"), m_Color2);
}

void UShieldComponent::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetOwner() != GetOwner())
	{
		if (AProjectile* Projectile = Cast<AProjectile>(OtherActor))
		{
			FHitResult Hit(ForceInit);
			FCollisionQueryParams Params = FCollisionQueryParams(FName(TEXT("ProjectileOverlapTrace")), false, Projectile);
			FVector NegatedTraceDirection = Projectile->GetActorLocation() - GetComponentLocation();
			NegatedTraceDirection.Normalize();
			GetWorld()->LineTraceSingleByChannel(Hit, Projectile->GetActorLocation() + NegatedTraceDirection * 100.f,
				GetComponentLocation(), ECC_GameTraceChannel3, Params);
			Projectile->OnHit(Projectile, GetOwner(), Hit.ImpactNormal * Projectile->GetVelocity().Size(), Hit);
		}
	}
}

void UShieldComponent::InitializeImpactArray()
{
	for (int32 i = 0; i < m_NumberOfPossibleImpacts; i++)
	{
		_AvailableIndices.Add(i);
		_IndexLifeTime.Add(i, 0);
		_BaseRadius.Add(i, 50);
	}
}

int32 UShieldComponent::GetIndex()
{
	if (_AvailableIndices.Num() > 0)
	{
		int32 Index = _AvailableIndices[0];
		UseIndex(Index);
		return Index;
	}
	FinishUsingIndex(_LastIndexUsed == m_NumberOfPossibleImpacts - 1 ? 0 : _LastIndexUsed + 1);
	return GetIndex();
}

void UShieldComponent::UseIndex(int32 Index)
{
	_IndexLifeTime[Index] = 0.f;
	_LastIndexUsed = Index;
	//SetComponentTickEnabled(true);
	_AvailableIndices.Remove(Index);
	_IndicesInUse.Add(Index);
}

void UShieldComponent::FinishUsingIndex(int32 Index)
{
	_IndicesInUse.Remove(Index);
	_AvailableIndices.Add(Index);
	if (_IndicesInUse.Num() == 0)
	{
		//SetComponentTickEnabled(false);
	}
}

void UShieldComponent::UpdateImpacts(float DeltaTime)
{
	for (int32 i = _IndicesInUse.Num() - 1; i >= 0; i--)
	{
		int32 Index = _IndicesInUse[i];
		float TimeAlive = _IndexLifeTime[Index] + DeltaTime;
		if (TimeAlive >= m_ImpactLifetime)
		{
			FinishUsingIndex(Index);
		}
		else
		{
			FString ParamName(TEXT("Radius_"));
			ParamName += FString::FromInt(Index);
			float Radius = _BaseRadius[Index] * _RadiusCurve->GetFloatValue(TimeAlive);
			_DynamicMaterial->SetScalarParameterValue(FName(*ParamName), FMath::Max(Radius, 0.f));
			_IndexLifeTime[Index] = TimeAlive;
		}
	}
}
