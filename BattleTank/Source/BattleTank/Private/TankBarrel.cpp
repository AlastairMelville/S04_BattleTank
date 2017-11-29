// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"



void UTankBarrel::Elevate(float move_degrees_per_second)
{
	UE_LOG(LogTemp, Warning, TEXT("barrel is moving at %f per second"), degrees_per_second);
}
