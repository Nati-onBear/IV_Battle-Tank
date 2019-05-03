// Copyright Nati-onBear Property


#include "TankPlayerController.h"
#include "Engine/World.h"

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
	FVector2D Crosshair = GetCrosshair();
	
	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(Crosshair, OUT LookDirection))
	{
		// Line-trace along that look direction, and see what we hit (at max range)
		GetLookVectorHitLocation(LookDirection, OUT OutHitLocation);
	}
	
	return true;
}

FVector2D ATankPlayerController::GetCrosshair() const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(OUT ViewportSizeX, OUT ViewportSizeY);
	return FVector2D((CrosshairXLocation * (float)ViewportSizeX), (CrosshairYLocation * (float)ViewportSizeY));
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // Don't care
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, OUT CameraWorldLocation, OUT LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			OUT HitResult,
			StartLocation,
			StartLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
		return true;
	}
	HitLocation = FVector(0);
	return false;
}

void ATankPlayerController::AimAtCrosshair()
{
	// Protecting pointer
	if (!ControlledTank) { return; }

	FVector HitLocation; // OUT parameter
	// if (hit landscape)
	if (GetSightRayHitLocation( OUT HitLocation ))
	{
		// TODO Tell controlled tank to aim at that point
		
	}
}
