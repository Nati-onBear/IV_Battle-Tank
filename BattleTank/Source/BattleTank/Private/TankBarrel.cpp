// Copyright Nati-onBear Property


#include "TankBarrel.h"
#include "Engine/World.h"				// for GetWorld()->....

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Given max elevation speed and frame time
	// Move barrel right amount every frame
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = RelativeSpeed * MaxDegreePerSec * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = FMath::Clamp<float>(RelativeRotation.Pitch + ElevationChange, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(NewElevation, 0, 0));
}