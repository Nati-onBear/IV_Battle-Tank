// Copyright Nati-onBear Property


#include "TankAIController.h"

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
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled tank: %s"), *ControlledTank->GetName());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
