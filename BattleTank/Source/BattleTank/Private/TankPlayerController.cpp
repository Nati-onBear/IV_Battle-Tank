// Copyright Nati-onBear Property


#include "TankPlayerController.h"

#define OUT

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed getting player controlled tank."));
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// Linetrace through crosshair to get world location
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);

	return true;
}

void ATankPlayerController::AimAtCrosshair()
{
	// Protecting pointer
	if (!ControlledTank) { return; }

	FVector HitLocation; // OUT parameter
	
	// if (hit landscape)
	if (GetSightRayHitLocation(HitLocation)) // I know, hard to understand
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
		// TODO Tell controlled tank to aim at that point
	}
}
