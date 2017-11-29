// Fill out your copyright notice in the Description page of Project Settings.

#include "TankController.h"
#include "Tank.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

void ATankController::BeginPlay()
{
	Super::BeginPlay();

	ATank* controlled_tank = GetTank();
	if (controlled_tank == nullptr) { return; }

	UE_LOG(LogTemp, Warning, TEXT("[%s] Controlled Tank: %s"), *this->GetName(), *controlled_tank->GetName())
}

void ATankController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

ATank* ATankController::GetTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankController::AimTowardsCrosshair()
{
	if (!GetTank()) { /* UE_LOG(LogTemp, Error, TEXT("[%s] Cannot find controlled tank"), *this->GetName()) */ return; }

	FVector2D hit_location; 
	FVector aim_location;
	if (GetSightRayHitLocation(hit_location, aim_location))
	{
		GetTank()->AimTowardsTarget(aim_location);
		/// UE_LOG(LogTemp, Warning, TEXT("[%s] hit: %s"), *this->GetName(), *hit_location.ToString())
	}
}

bool ATankController::GetSightRayHitLocation(FVector2D& out_hit_location, FVector& aim_location) const
{
	// Create Aim Reticule Screen Location
	int32 screen_location_x, screen_location_y;
	GetViewportSize(screen_location_x, screen_location_y);
	FVector2D aim = FVector2D(screen_location_x * reticule_location_x, screen_location_y * reticule_location_y);

	// Make that 2D location 3D
	FVector camera_world_location; 
	FVector camera_world_direction;
	if (DeprojectScreenPositionToWorld(aim.X, aim.Y, camera_world_location, camera_world_direction))
	{	
		// If the 2D location is successfully turned into a 3D location, a line trace is started
		FHitResult hit;
		FVector start;
		if (GetWorld()->LineTraceSingleByChannel(hit, PlayerCameraManager->GetCameraLocation(), camera_world_location + (camera_world_direction * aim_range), ECollisionChannel::ECC_Visibility)) 
		{
			// If the line trace hits something, that something is identified
			/// UE_LOG(LogTemp, Warning, TEXT("[%s] Look direcion: %s"), *this->GetName(), *hit.GetActor()->GetName())
			aim_location = hit.Location;
			return true;
		}
	}

	return false;
}
