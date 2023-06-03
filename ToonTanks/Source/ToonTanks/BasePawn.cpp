// Fill out your copyright notice in the Description page of Project Settings.

#include "BasePawn.h"
#include "Components/CapsuleComponent.h"

/**
 * @brief 
 * Construct a new ABasePawn::ABasePawn object
 */
ABasePawn::ABasePawn()
{
	PrimaryActorTick.bCanEverTick = true;

	// Capsule collider
	m_capsule_component = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = m_capsule_component;
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

/**
 * @brief
 * Sets up the player input component
 * @param PlayerInputComponent Input component to set up
 */
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

