// Fill out your copyright notice in the Description page of Project Settings.


#include "RoombaPlayerController.h"

void ARoombaPlayerController::BeginPlay()
{
	Super::BeginPlay();

	BatteryCharge = 100.f;
}

float ARoombaPlayerController::getBatteryCharge() const
{
	return BatteryCharge;
}

void ARoombaPlayerController::subBatteryCharge(float DeltaTime)
{
	BatteryCharge -= DeltaTime;
}
