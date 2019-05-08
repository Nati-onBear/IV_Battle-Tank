// Copyright Nati-onBear Property

#include "TankAimingComponent.h"
#include "TankBarrel.h"							// get the inhirited methods of TankBarrel: GetSocketLocation
#include "TankTurret.h"
#include "GameFramework/Actor.h"				// for GetOwner()->...
#include "Components/StaticMeshComponent.h"		// for UStaticMeshComponent*->...
#include "Kismet/GameplayStatics.h"				// for UGameplayStatics::...

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;		// TODO decide if this needs to tick
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation("Projectile");
	
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
		MoveComponent(AimDirection);
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* Barrel) {  this->Barrel = Barrel; }

void UTankAimingComponent::SetTurretReference(UTankTurret* Turret) { this->Turret = Turret; }

void UTankAimingComponent::MoveComponent(FVector AimDirection)
{
	if (!Barrel || !Turret) { return; }
	
	// Get difference between current barrel rotation and of AimDirection
	auto CurrentBarrelRotator = Barrel->GetForwardVector().Rotation();
	auto CurrentTurretRotator = Turret->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaBarrelRotator = AimAsRotator - CurrentBarrelRotator;
	auto DeltaTurretRotator = AimAsRotator - CurrentTurretRotator;
	
	Barrel->Elevate(DeltaBarrelRotator.Pitch);
	Turret->Rotate(DeltaBarrelRotator.Yaw);
}
