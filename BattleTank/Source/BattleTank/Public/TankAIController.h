// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"					// Inherited
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

private:
	// How close a AI can get to player
	float AcceptableRadius = 1000;
};
