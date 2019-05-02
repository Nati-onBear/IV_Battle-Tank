// Copyright Nati-onBear Property


#include "TankAIController.h"
#include "Engine/World.h"						// for GetWorld()->....
#include "GameFramework/PlayerController.h"		// for GetFirstPlayerController()->...


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed getting AI controlled tank."));
	}
	else
	{
		auto PlayerTank = GetPlayerTank();

		UE_LOG(LogTemp, Warning, TEXT("AI Controlled tank %s aiming for %s"), *ControlledTank->GetName(), *PlayerTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerTank;

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (!PlayerTank) { return nullptr; }

	return PlayerTank;
}
