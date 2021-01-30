// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RoombaPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GGJ_ROOMBA_API ARoombaPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintGetter=getBatteryCharge)
	float BatteryCharge;

public:
	UFUNCTION(BlueprintCallable)
	float getBatteryCharge() const;

	UFUNCTION(BlueprintCallable)
	void subBatteryCharge(float DeltaTime);
};
