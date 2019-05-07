// Copyright Nati-onBear Property


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	// Given max rotation speed and frame time
	// Move turret right amount every frame
	//UE_LOG(LogTemp, Warning, TEXT("Rotating Turret"));
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto RotationChange = RelativeSpeed * MaxDegreePerSec * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	//auto NewElevation = FMath::Clamp<float>(RelativeRotation.Pitch + RotationChange, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}