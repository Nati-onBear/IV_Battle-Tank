// Copyright Nati-onBear Property

#include "TankAimingComponent.h"
#include "TankBarrel.h"							// get the inhirited methods of TankBarrel: GetSocketLocation
#include "GameFramework/Actor.h"				// for GetOwner()->...
#include "Components/StaticMeshComponent.h"		// for UStaticMeshComponent*->...
#include "Kismet/GameplayStatics.h"				// for UGameplayStatics::...

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;		// TODO decide if this needs to tick
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!OwnerBarrel) { return; }

	FVector OutLaunchVelocity(0);
	FVector StartLocation = OwnerBarrel->GetSocketLocation("Projectile");
	
	// Calculate the OutLaunchVelocity, This is NOT WORKING, Found aim solution even when pointing at sky
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0
		,ESuggestProjVelocityTraceOption::DoNotTrace	// Comment this line to reproduce bug
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
	else
	{
		auto time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: No aim solution!"), time);
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* Barrel) { this->OwnerBarrel = Barrel; }

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	if (!OwnerBarrel) { return; }
	
	// Get difference between current barrel pitch and of AimDirection
	auto BarrelRotator = OwnerBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	OwnerBarrel->Elevate(DeltaRotator.Pitch);	// TODO remove magic number
}

