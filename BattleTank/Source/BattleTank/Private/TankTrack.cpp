// Copyright Nati-onBear Property


#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	// TODO clamp real throttle value
	auto ForceApplied = GetForwardVector() * Throttle * MaxDriveForce;
	auto ForceLocation = GetComponentLocation();

	// Get tank body
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}