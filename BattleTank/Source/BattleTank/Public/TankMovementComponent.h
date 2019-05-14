// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * Control left and right tracks speed with Fly-by-Wire Control System
 */
UCLASS()
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Moving)
	void IntendMoveFoward(float Throw);
	
};
