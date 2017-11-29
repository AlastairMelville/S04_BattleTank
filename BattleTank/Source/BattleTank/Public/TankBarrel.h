// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	void Elevate(float move_degrees_per_second);
	

private:
	UPROPERTY(EditAnywhere, Category = "Firing")
		float degrees_per_second = 20.f;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float min_pitch = 0.f;

	UPROPERTY(EditAnywhere, Category = "Firing")
		float max_pitch = 30.f;
};
