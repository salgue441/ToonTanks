/**
 * @file BasePawn.h
 * @Brief Base class for all pawns in the game
 * @author Carlos Salguero
 * @version 0.0.1
 * @date 2023-06-02
 * 
 * @copyright Copyright (c) 2023 - Carlos Salguero
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

protected:
	// Methods
	void rotate_turret(FVector);

private:
	// Components
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", 
		meta = (AllowPrivateAccess = "true"))
		class UCapsuleComponent *m_capsule_component;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components",
		meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *m_base_mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components",
		meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *m_turret_mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components",
		meta = (AllowPrivateAccess = "true"))
		USceneComponent *m_projectile_spawn_point;
};
