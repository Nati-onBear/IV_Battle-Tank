// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"		// Inherited
#include "TankAimingComponent.generated.h"

// Forward Declaration: let header know that the class exist
class UTankBarrel;		

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UTankBarrel*);

	// TODO make SetTurretReference

private:
	UTankBarrel* OwnerBarrel = nullptr;

	// Method for rotating barrel in PITCH (Y value)
	void MoveBarrel(FVector AimDirection);
};
