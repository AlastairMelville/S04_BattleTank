// Fill out your copyright notice in the Description page of Project Settings.

/// #include "TankAIController.h"
#include "../Public/TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	// Get your controlled tank
	ATank* controlled_tank = GetTank();
	if (controlled_tank == nullptr) { UE_LOG(LogTemp, Error, TEXT("[%s] Controlled tank is a nullptr"), *this->GetName()) return; }

	UE_LOG(LogTemp, Warning, TEXT("[%s] Controlled tank: %s"), *this->GetName(), *controlled_tank->GetName())

	// Get player-controlled tank
	APawn* player_tank = GetPlayerTank();
	if (player_tank == nullptr) { UE_LOG(LogTemp, Error, TEXT("[%s] Player tank is a nullptr"), *this->GetName()) return; }

	UE_LOG(LogTemp, Warning, TEXT("[%s] Player tank: %s"), *this->GetName(), *player_tank->GetName())
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankAIController::GetTank() const 
{
	return Cast<ATank>(GetPawn());
}

APawn* ATankAIController::GetPlayerTank() const
{
	auto player_tank = GetWorld()->GetFirstPlayerController()->GetPawn();
	return player_tank;
}

void ATankAIController::AimTowardsCrosshair()
{
	if (!GetTank()) { UE_LOG(LogTemp, Error, TEXT("[%s] Cannot find controlled tank"), *this->GetName()) return; }


}

