/**
 * @file Tank.cpp
 * @brief This file contains the implementation of the Tank class
 * @author Carlos Salguero
 * @date 2023-06-02
 * @version 1.0
 *
 * @copyright Copyright (c) 2023 - Carlos Salguero
 */

#include "Tank.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

/**
 * @brief
 * Construct a new ATank::ATank object
 * Sets default values for this pawn's properties
 * @details
 * It also creates the spring arm component and the camera component.
 */
ATank::ATank()
{
	// Spring arm component
	m_spring_arm_component = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	m_spring_arm_component->SetupAttachment(RootComponent);

	// Camera component
	m_camera_component = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	m_camera_component->SetupAttachment(m_spring_arm_component);
}

// Methods (Public)
/**
 * @brief
 * Called to bind functionality to input
 * @param PlayerInputComponent
 */
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind axis
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::move);
}

// Methods (Private)
/**
 * @brief 
 * Moves the tank forward or backward
 * @param value Value to move the tank
 */
void ATank::move(float value)
{
	FVector delta_location(0.f);
	delta_location.X = value;

	AddActorLocalOffset(delta_location, true);
}