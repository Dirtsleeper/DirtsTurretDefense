// Fill out your copyright notice in the Description page of Project Settings.

#include "BombVest.h"

#include "Player/Weapons/Projectiles/Projectile.h"


void UBombVest::OnFirePressed()
{
	SpawnProjectile(GetOwner()->GetActorTransform())->TriggerHit(GetOwner());
}
