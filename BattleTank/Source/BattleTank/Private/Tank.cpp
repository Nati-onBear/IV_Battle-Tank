// Copyright Nati-onBear Property

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"						// for GetWorld()->....
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{ 
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect pointer in constructor
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aming Component"));
	if (!TankAimingComponent) 
		UE_LOG(LogTemp, Warning, TEXT("No Tank Aiming Component"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) 
{ 
	if (!BarrelToSet) return;
	Barrel = BarrelToSet;
	TankAimingComponent->SetBarrelReference(BarrelToSet); 
}

void ATank::SetTurretReference(UTankTurret* TurretToSet) 
{ 
	if (!TurretToSet) return;
	TankAimingComponent->SetTurretReference(TurretToSet); 
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
