/**
 * @file Tank.h
 * @brief This file contains the declaration of the Tank class
 * @author Carlos Salguero
 * @date 2023-06-02
 * @version 1.0
 * 
 * @copyright Copyright (c) 2023 - Carlos Salguero
 */

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * @class ATank : public ABasePawn
 * @brief
 * Tank class that inherits from ABasePawn
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	// Macro
	GENERATED_BODY()

public:
	// Constructor
	ATank();

	// Methods
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void Tick(float DeltaTime) override;

protected:
	// Methods
	void BeginPlay() override;

private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class USpringArmComponent* m_spring_arm_component;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UCameraComponent* m_camera_component;

	// Variables
	UPROPERTY(EditAnywhere, Category = "Movement")
		float m_move_speed = 300.f;

	UPROPERTY(EditAnywhere, Category = "Movement")
		float m_rotate_speed = 100.f;

	// References
	APlayerController* m_player_controller;

	// Methods
	void move(float);
	void rotate(float);
};
