// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"		// Inherited
#include "TankAimingComponent.generated.h"

// Forward Declaration: let header know that the class exist
class UTankBarrel;		
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UTankBarrel*);

	void SetTurretReference(UTankTurret*);

	void Fire(TSubclassOf<AProjectile>);

private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	// Method for elevating barrel in PITCH (Y value) and rotating turret in YAW (Z value)
	void MoveComponent(FVector AimDirection);
};
