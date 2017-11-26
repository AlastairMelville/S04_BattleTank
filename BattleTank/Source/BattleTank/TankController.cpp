// Fill out your copyright notice in the Description page of Project Settings.

#include "TankController.h"
#include "Tank.h"


void ATankController::BeginPlay()
{
	ATank* controlled_tank = GetTank();
	if (controlled_tank == nullptr)
	{
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("[%s] Controlled Tank: %s"), *this->GetName(), *controlled_tank->GetName())
}

ATank* ATankController::GetTank() const 
{
	return Cast<ATank>(GetPawn());
}


