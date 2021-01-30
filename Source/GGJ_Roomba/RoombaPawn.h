// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RoombaMovementComponent.h"
#include "Materials/MaterialInstanceDynamic.h" 
#include "Particles/ParticleSystemComponent.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "RoombaPawn.generated.h"

UCLASS()
class GGJ_ROOMBA_API ARoombaPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARoombaPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Variables
	UCapsuleComponent* CapsuleComponent;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CapsuleVisual;
	UPROPERTY(EditAnywhere)
	URotatingMovementComponent* RotatingComponent;

	UPROPERTY()
	UMaterialInstanceDynamic* MaterialInstance;
	UPROPERTY()
	UMaterialInterface* MaterialDynamic;

	bool RoombaMoving;
	bool RoombaHit;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
	class URoombaMovementComponent* MovementComponent;

	virtual URoombaMovementComponent* GetMovementComponent() const override;

	void StartMoving();
	void StopMoving();
};
