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
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);

	FVector2D Crosshair = FVector2D((CrosshairXLocation * (float)ViewportSizeX), (CrosshairYLocation * (float)ViewportSizeY));

	UE_LOG(LogTemp, Warning, TEXT("%s"), *Crosshair.ToString());
	// "De-project" the screen position of the crosshair to a world direction
	// Line-trace along that look direction, and see what we hit (at max range)

	return true;
}

void ATankPlayerController::AimAtCrosshair()
{
	// Protecting pointer
	if (!ControlledTank) { return; }

	FVector HitLocation; // OUT parameter
	
	// if (hit landscape)
	if (GetSightRayHitLocation( OUT HitLocation )) // I know, hard to understand
	{
		// TODO Tell controlled tank to aim at that point
	}
}
