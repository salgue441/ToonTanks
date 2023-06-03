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

/**
 * @brief
 * Called when the game starts or when spawned
 */
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

/**
 * @brief
 * Called every frame
 */
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

