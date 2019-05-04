// Copyright Nati-onBear Property

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	ATank* ControlledTank;
	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	// Find the crosshair position in pixel coordinates
	FVector2D GetCrosshair() const;

	// "De-project" the screen position of the crosshair to a world direction
	bool GetLookDirection(FVector2D, FVector&) const;

	// Line-trace along that look direction, and see what we hit (at max range)
	bool GetLookVectorHitLocation(FVector, FVector&) const;

	// Move the barrel for projectile to hit where the crosshair intersects with world
	void AimAtCrosshair();

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = (float)1 / 3;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 10000000000.f; // how far the tank can line trace
};
