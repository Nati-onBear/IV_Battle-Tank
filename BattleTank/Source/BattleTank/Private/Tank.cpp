// Copyright Nati-onBear Property

#include "Tank.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{ 
	PrimaryActorTick.bCanEverTick = false;

	ThisTankName = GetName();
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

