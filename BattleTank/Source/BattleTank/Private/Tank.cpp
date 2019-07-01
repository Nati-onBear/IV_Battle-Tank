// Copyright Nati-onBear Property

#include "Tank.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"
#include "Engine/World.h"						// for GetWorld()->....
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{ 
	PrimaryActorTick.bCanEverTick = false;
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) 
{ 
	if (!BarrelToSet) return;
	Barrel = BarrelToSet;
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSec;

	if (Barrel && isReloaded)
	{
		FVector  SpawnLocation = Barrel->GetSocketLocation("Projectile");
		FRotator SpawnRotation = Barrel->GetSocketRotation("Projectile");

		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, SpawnLocation, SpawnRotation);

		Projectile->LaunchProjectile(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds(); // Reset
	}
}
