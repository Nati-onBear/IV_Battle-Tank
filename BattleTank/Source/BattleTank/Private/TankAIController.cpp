// Copyright Nati-onBear Property

#include "Tank.h"
#include "TankAIController.h"
#include "Engine/World.h"						// for GetWorld()->....
#include "GameFramework/PlayerController.h"		// for GetFirstPlayerController()->...


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed getting AI controlled tank."));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtPlayer();
}

ATank* ATankAIController::GetControlledTank() const { return Cast<ATank>(GetPawn()); }

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!PlayerTank) { return nullptr; }

	return PlayerTank;
}

void ATankAIController::AimAtPlayer() const
{
	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank) { return; }

	auto PlayerLocation = PlayerTank->GetActorLocation();
	
	// TODO move towards player location

	ControlledTank->AimAt(PlayerLocation);

	// TODO fire if ready
}
