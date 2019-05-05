// Copyright Nati-onBear Property


#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreePerSec)
{
	// Given max elevation speed and frame time
	// Move barrel right amount every frame
	UE_LOG(LogTemp, Warning, TEXT("Barrel elevates at speed %f"), DegreePerSec);
}