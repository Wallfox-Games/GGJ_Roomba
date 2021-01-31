// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "RoombaGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class GGJ_ROOMBA_API URoombaGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintGetter = getBatteryCharge)
		float BatteryCharge;

public:
	UFUNCTION(BlueprintCallable)
	void setBatteryCharge();
	 
	UFUNCTION(BlueprintCallable)
	float getBatteryCharge() const;

	UFUNCTION(BlueprintCallable)
	void subBatteryCharge(float DeltaTime);
};
