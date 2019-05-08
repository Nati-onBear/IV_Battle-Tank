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

public:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;
};
