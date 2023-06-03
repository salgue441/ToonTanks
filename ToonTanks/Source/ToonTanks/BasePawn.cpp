/**
 * @file BasePawn.cpp
 * @brief This file contains the implementation of the BasePawn class
 * @author Carlos Salguero
 * @date 2023-06-02
 * @version 1.0
 *
 * @copyright Copyright (c) 2023 - Carlos Salguero
 */

#include "BasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"

/**
 * @brief 
 * Construct a new ABasePawn::ABasePawn object
 * Sets default values for this pawn's properties
 * @details
 * It also creates the capsule collider, the base mesh, the turret mesh and the projectile spawn point.
 */
ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	// Capsule collider
	m_capsule_component = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = m_capsule_component;

	// Base mesh
	m_base_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	m_base_mesh->SetupAttachment(RootComponent);

	// Turret mesh
	m_turret_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	m_turret_mesh->SetupAttachment(m_base_mesh);

	// Projectile spawn point
	m_projectile_spawn_point = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	m_projectile_spawn_point->SetupAttachment(m_turret_mesh);
}

// Methods (Protected)
/**
 * @brief
 * Rotates the turrent.
 * @param look_at_target The target to look at.
 */
void ABasePawn::rotate_turret(FVector look_at_target)
{
	FVector to_target = look_at_target - m_turret_mesh->GetComponentLocation();
	FRotator to_target_rotation = FRotator(0.f, to_target.Rotation().Yaw, 0.f);

	m_turret_mesh->SetWorldRotation(to_target_rotation);
}

