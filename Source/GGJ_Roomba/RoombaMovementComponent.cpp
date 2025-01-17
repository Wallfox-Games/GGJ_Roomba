// Fill out your copyright notice in the Description page of Project Settings.


#include "RoombaMovementComponent.h"
#include "Engine.h"
#include "Math/Vector.h" 

void URoombaMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    CurrentlyHit = false;

    // Make sure that everything is still valid, and that we are allowed to move.
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }

    FVector DesiredMovementThisFrame = FVector(0.f, 0.f, -2.f) * DeltaTime * 150.0f;
    if (!DesiredMovementThisFrame.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

        // If we bumped into something, adjust rotation to match normal
        if (Hit.IsValidBlockingHit())
        {
            //GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, FString::SanitizeFloat(Hit.Normal.Z));
            if (Hit.Normal.Z < 0.4)
            {
                DesiredMovementThisFrame = FVector(0.f, 0.f, -0.5f) * DeltaTime * 150.0f;
                SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
            }
            GroundNormal = Hit.Normal;
        }
    }

    // Get (and then clear) the movement vector that we set in ACollidingPawn::Tick
    DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;
    if (!DesiredMovementThisFrame.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

        // If we bumped into something, try to slide along it
        if (Hit.IsValidBlockingHit())
        {            
            CurrentlyHit = true;
            SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
        }
    }
};