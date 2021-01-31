// Fill out your copyright notice in the Description page of Project Settings.


#include "RoombaGameInstance.h"

void URoombaGameInstance::setBatteryCharge()
{
	BatteryCharge = 100.f;
}

float URoombaGameInstance::getBatteryCharge() const
{
	return BatteryCharge / 100.f;
}

void URoombaGameInstance::subBatteryCharge(float DeltaTime)
{
	BatteryCharge -= DeltaTime;
}