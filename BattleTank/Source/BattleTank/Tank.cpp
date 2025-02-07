// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "../Public/TankAimingComponent.h"
#include "../Public/TankBarrel.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	tank_aiming_component = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel* barrel_to_reference)
{
	tank_aiming_component->SetBarrelReference(barrel_to_reference);
}

void ATank::AimTowardsTarget(FVector aim_location)
{
	tank_aiming_component->AimAt(aim_location, launch_speed);
}

