// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// Foward declare Tank Barrel
class UTankBarrel;

// Declares and Defines the aiming variables of Tank Barrel
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector aim_location, float launch_speed);

	void SetBarrelReference(UTankBarrel* barrel_to_reference);

protected:


private:	
	
	UTankBarrel* barrel = nullptr;

	void MoveBarrel(FVector aim_direction);

};
