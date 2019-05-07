// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);

private:
	//Sensible default
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreePerSec = 30;
};
