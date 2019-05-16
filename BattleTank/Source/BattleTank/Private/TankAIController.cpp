// Copyright Nati-onBear Property

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"						// for GetWorld()->....
#include "GameFramework/PlayerController.h"		// for GetFirstPlayerController()->...

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto ControlledTank = Cast<ATank>(GetPawn());
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	if (PlayerTank)
	{
		// Move towards player location
		MoveToActor(PlayerTank, AcceptableRadius); // Check unit of Radius

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// TODO fire if ready
		//ControlledTank->Fire();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Player Tank"));
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
