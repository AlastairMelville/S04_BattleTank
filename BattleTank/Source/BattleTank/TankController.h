// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Aiming")
		float reticule_location_x = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Aiming")
		float reticule_location_y = 0.3333f;

	UPROPERTY(EditAnywhere)
		float aim_range = 200000.f;

private:
	ATank* GetTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector2D& out_hit_location, FVector& aim_location) const;
	
protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
