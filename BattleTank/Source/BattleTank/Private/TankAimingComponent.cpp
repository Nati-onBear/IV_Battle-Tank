// Copyright Nati-onBear Property

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"				// for GetOwner()->...
#include "Components/StaticMeshComponent.h"		// for UStaticMeshComponent*->...

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!OwnerBarrel) { return; }
	UE_LOG(LogTemp, Warning, TEXT("Lauching Speed: %f"), LaunchSpeed);
}

void UTankAimingComponent::SetBarrelReference(UStaticMeshComponent* Barrel) { this->OwnerBarrel = Barrel; }

void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

