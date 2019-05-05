// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UStaticMeshComponent*);

	// TODO make SetTurretReference

private:
	UStaticMeshComponent* OwnerBarrel = nullptr;

	// Method for rotating barrel in PITCH (Y value)
	void MoveBarrel(FVector AimDirection);
};
