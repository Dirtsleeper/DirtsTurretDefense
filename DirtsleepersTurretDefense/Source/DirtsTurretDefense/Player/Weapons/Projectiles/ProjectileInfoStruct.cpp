// Fill out your copyright notice in the Description page of Project Settings.

#include "ProjectileInfoStruct.h"




UParticleSystem* FProjectileInfo::GetImpactParticle(EImpactMaterial Material)
{
	switch (Material)
	{
	case EImpactMaterial::Body:
		return Impact_Body;
	case EImpactMaterial::Metal:
		return Impact_Metal;
	case EImpactMaterial::Terrain:
	default:
		return Impact_Terrain;
	}
}
