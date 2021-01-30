// Fill out your copyright notice in the Description page of Project Settings.


#include "RoombaPawn.h"

// Sets default values
ARoombaPawn::ARoombaPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Our root component will be a sphere that reacts to physics
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("RootComponent"));
	RootComponent = CapsuleComponent;
	CapsuleComponent->SetCapsuleHalfHeight(1.5f);
	CapsuleComponent->SetCapsuleRadius(20.f);
	CapsuleComponent->SetCollisionProfileName(TEXT("Pawn"));

	CapsuleVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
	CapsuleVisual->SetupAttachment(RootComponent);

	// Use a spring arm to give the camera smooth, natural-feeling motion.
	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	SpringArm->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	SpringArm->TargetArmLength = 800.f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;
	SpringArm->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera and attach to our spring arm
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Take control of the default player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create an instance of our movement component, and tell it to update the root.
	MovementComponent = CreateDefaultSubobject<URoombaMovementComponent>(TEXT("CustomMovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;

	// Create the rotation component
	RotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("CustomRotationComponent"));
	RotatingComponent->UpdatedComponent = RootComponent;
	RotatingComponent->SetActive(true);
}

// Called when the game starts or when spawned
void ARoombaPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARoombaPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (RoombaMoving && MovementComponent && (MovementComponent->UpdatedComponent == RootComponent))
	{
		MovementComponent->AddInputVector(GetActorForwardVector());
	}
}

// Called to bind functionality to input
void ARoombaPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Movement", IE_Pressed, this, &ARoombaPawn::StartMoving);
	PlayerInputComponent->BindAction("Movement", IE_Released, this, &ARoombaPawn::StopMoving);
}

URoombaMovementComponent* ARoombaPawn::GetMovementComponent() const
{
	return MovementComponent;
}

void ARoombaPawn::StartMoving()
{
	RotatingComponent->SetActive(false);
	RoombaMoving = true;
}

void ARoombaPawn::StopMoving()
{
	RotatingComponent->SetActive(true);
	RoombaMoving = false;
}

