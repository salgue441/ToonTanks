/**
 * @file BasePawn.h
 * @Brief Base class for all pawns in the game
 * @author Carlos Salguero
 * @version 0.0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023 - Carlos Salg
 */
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

/**
 * @class ABasePawn : public APawn
 * @brief Base class for all pawns in the game
 * @details
 * This class is the base class for all pawns in the game. It is a child of APawn.
 */
UCLASS()
class TOONTANKS_API ABasePawn : public APawn
{
	// Macro
	GENERATED_BODY()

public:
	// Constructor
	ABasePawn();

	// Methods
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY()
	class UCapsuleComponent *m_capsule_component;
};
