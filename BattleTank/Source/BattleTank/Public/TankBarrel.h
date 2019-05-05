// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) , hidecategories = ("Collision") )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreePerSec);

private:
	//Sensible default
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSec = 10;	

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevation = 40;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevation = 0;
};
