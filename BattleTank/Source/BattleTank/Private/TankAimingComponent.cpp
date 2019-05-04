// Copyright Nati-onBear Property

#include "TankAimingComponent.h"
#include "GameFramework/Actor.h"				// for GetOwner()->...
#include "Components/StaticMeshComponent.h"		// for UStaticMeshComponent*->...

UTankAimingComponent::UTankAimingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!OwnerBarrel) { return; }
	auto OwnerTankName = GetOwner()->GetName();
	auto BarrelLocation = OwnerBarrel->GetComponentLocation().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *OwnerTankName, *HitLocation.ToString(), *BarrelLocation);
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

