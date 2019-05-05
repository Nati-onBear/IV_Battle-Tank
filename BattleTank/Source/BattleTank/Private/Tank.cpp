// Copyright Nati-onBear Property

#include "Tank.h"

// Sets default values
ATank::ATank()
{ 
	PrimaryActorTick.bCanEverTick = true;

	ThisTankName = GetName();
	// No need to protect pointer in constructor
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aming Component"));
	if (!TankAimingComponent) 
		UE_LOG(LogTemp, Warning, TEXT("No Tank Aiming"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

