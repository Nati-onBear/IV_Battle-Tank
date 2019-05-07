// Copyright Nati-onBear Property

#include "Tank.h"
#include "TankPlayerController.h"
#include "Engine/World.h"				// for GetWorld()->....

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

ATank* ATankPlayerController::GetControlledTank() const { return Cast<ATank>(GetPawn()); }

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
		if (GetLookVectorHitLocation(LookDirection, OUT OutHitLocation))
			return true;
	}
	
	return false;
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
	
	// Draw debug trace
	/*static FName TraceTag = TEXT("TraceTag");
	GetWorld()->DebugDrawTraceTag = TraceTag;
	FCollisionQueryParams Params(TraceTag);*/

	if (GetWorld()->LineTraceSingleByChannel(
		OUT HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
		))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}

void ATankPlayerController::AimAtCrosshair()
{
	// Protecting pointer
	if (!ControlledTank) { return; }

	FVector HitLocation;

	// if (hit landscape)
	if (GetSightRayHitLocation( OUT HitLocation ))
	{
		// Tell controlled tank to aim at that point
		ControlledTank->AimAt(HitLocation);
	}
}
