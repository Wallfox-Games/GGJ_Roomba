// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PawnMovementComponent.h"
#include "RoombaMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class GGJ_ROOMBA_API URoombaMovementComponent : public UPawnMovementComponent
{
	GENERATED_BODY()

protected:
	bool CurrentlyHit;
	FVector GroundNormal;

public:
	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool getCurrentlyHit() { return CurrentlyHit; };
	FVector getGroundNormal() { return GroundNormal; };
};
