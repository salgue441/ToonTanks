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
	m_spring_arm_component = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm Component"));
	m_spring_arm_component->SetupAttachment(RootComponent);

	m_camera_component = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	m_camera_component->SetupAttachment(m_spring_arm_component);
}