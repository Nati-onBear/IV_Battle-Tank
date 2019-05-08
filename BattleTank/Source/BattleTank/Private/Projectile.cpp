// Copyright Nati-onBear Property


#include "Projectile.h"
#include "TankProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	TankProjectileMovement = CreateDefaultSubobject<UTankProjectileMovementComponent>(FName("Projectile Movement"));
	TankProjectileMovement->bAutoActivate = false;

	if (!TankProjectileMovement)
	{
		UE_LOG(LogTemp, Warning, TEXT("No Tank Projectile Movement Component"));
	}
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::LaunchProjectile(float Speed)
{
	TankProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	TankProjectileMovement->Activate();
}

