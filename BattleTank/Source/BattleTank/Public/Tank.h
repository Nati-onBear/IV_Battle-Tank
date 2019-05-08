// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"		// Inherited
#include "Tank.generated.h"

// Forward Declarations
class UTankBarrel;	
class UTankTurret;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

public:
	virtual void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

private:
	ATank();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FString ThisTankName;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000; // TODO find sensible default

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();
};
