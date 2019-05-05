// Copyright Nati-onBear Property

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"				// for GetOwner()->...
#include "Components/StaticMeshComponent.h"		// for UStaticMeshComponent*->...
#include "Kismet/GameplayStatics.h"				// for UGameplayStatics::...

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!OwnerBarrel) { return; }

	FVector OutLaunchVelocity(0);
	FVector StartLocation = OwnerBarrel->GetSocketLocation("Projectile");
	
	// Calculate the OutLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0.f,
		9.8f,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		auto TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s"), *TankName,*AimDirection.ToString());
		MoveBarrel(AimDirection);
	}
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* Barrel) { this->OwnerBarrel = Barrel; }

void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	if (!OwnerBarrel) { return; }
	
	// Get difference between current barrel pitch and of AimDirection
	auto BarrelRotator = OwnerBarrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsRotator.ToString());
	// Given max elevation speed and frame time
	// Move barrel right amount every frame
}

