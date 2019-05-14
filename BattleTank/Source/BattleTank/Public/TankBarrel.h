// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, +1 is max upward speed
	void Elevate(float RelativeSpeed);

private:
	//Sensible default
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreePerSec = 20;	

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevation = 60;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevation = -10;
};
