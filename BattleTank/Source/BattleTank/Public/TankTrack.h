// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Set max driving force and apply forces to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	// Max force per track in Newton (F = ma)
	UPROPERTY(EditDefaultsOnly)
	float MaxDriveForce = 500000; // Assume that a tank of 50 tons and an acceleration of 10m/s^2
};
