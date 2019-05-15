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

	// Max force per track in Newton (F(N) = m(kg)a(m/s^2))
	UPROPERTY(EditDefaultsOnly)
	float MaxDriveForce = 40000000; // Assume that a tank of 50 tons and an acceleration of 10m/s^2
	// Note that default units in Unreal are N, kg, cm not m
};
