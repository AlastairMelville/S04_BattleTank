// Fill out your copyright notice in the Description page of Project Settings.


#include "../Public/TankAimingComponent.h"
#include "../Public/TankBarrel.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * barrel_to_reference)
{
	barrel = barrel_to_reference;
}

void UTankAimingComponent::AimAt(FVector hit_location, float launch_speed)
{	
	if (barrel != nullptr) 
	{
		FVector barrel_location = barrel->GetComponentLocation();
		FVector OUT_launch_velocity;
		FVector start_location = barrel->GetSocketLocation(FName("Launch_Position"));
		if (UGameplayStatics::SuggestProjectileVelocity(this, OUT_launch_velocity, start_location, hit_location, launch_speed, ESuggestProjVelocityTraceOption::DoNotTrace)) 
		{
			FVector aim_direction = OUT_launch_velocity.GetSafeNormal();
			/// UE_LOG(LogTemp, Warning, TEXT("[%s] is aiming at %s"), *GetOwner()->GetName(), *aim_direction.ToCompactString());
			MoveBarrel(aim_direction);
		}		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("[%s] is aiming at %s. But barrel cannot be found!"), *GetOwner()->GetName(), *hit_location.ToCompactString());
	}
}

void UTankAimingComponent::MoveBarrel(FVector aim_direction) 
{
	if (barrel == nullptr) { UE_LOG(LogTemp, Error, TEXT("barrel is a nullptr")) return; }

	FRotator barrel_rotation = barrel->GetForwardVector().Rotation();
	FRotator aim_rotation = aim_direction.Rotation();
	FRotator delta_rotator = aim_rotation - barrel_rotation;
	/// UE_LOG(LogTemp, Warning, TEXT("[%s] is aiming at %s"), *GetOwner()->GetName(), *delta_rotator.ToString());

	barrel->Elevate(5);
}
