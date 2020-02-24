// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeJoystickTest.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/LightComponent.h"
#include "Components/SpotLightComponent.h"
#include "Helicopter Logic/ApacheJoystick.h"
// Sets default values
ACubeJoystickTest::ACubeJoystickTest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Set this pawn to be controlled by the lowest-numbered player
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create a dummy root component we can attach things to.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	// Create a camera and a visible object

	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	Cube = CreateDefaultSubobject<UStaticMeshComponent>("Cube");



	Multiplier = 20065116.0f;

	// Attach our camera and visible object to our root component. Offset and rotate the camera.

	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	Rotor = CreateDefaultSubobject<UStaticMeshComponent>("Rotor");
	Gun = CreateDefaultSubobject<UStaticMeshComponent>("Gun");
	Gun->SetRelativeLocation(FVector(350.0, 0, -90.0f));
	Rotor->SetRelativeLocation(FVector(0, 0, 51.0f));
	FAttachmentTransformRules ARules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
	OurCamera->SetupAttachment(Cube);
	Cube->AttachToComponent(RootComponent, ARules);
	Rotor->AttachToComponent(Cube, ARules);
	Gun->AttachToComponent(Cube, ARules);
	
	Rotor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Gun->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
// Called when the game starts or when spawned
void ACubeJoystickTest::BeginPlay()
{

	Super::BeginPlay();

}
void ACubeJoystickTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}
// Called every frame
void ACubeJoystickTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	JoystickRotation.X = FMath::Clamp(JoystickRotation.X, -90.0f, 90.0f);
	JoystickRotation.Y = FMath::Clamp(JoystickRotation.Y, -90.0f, 90.0f);
	JoystickRotation.Z = FMath::Clamp(JoystickRotation.Z, -90.0f, 90.0f);
	ApacheRotation = JoystickRotation * Multiplier;	
	Cube->AddTorqueInDegrees(ApacheRotation);
	PropellorRotation = FMath::Clamp(PropellorRotation, 0.0f, 7.0f);
	FRotator  TempRotation = FRotator(PropellorRotation, 0, 0);
	FQuat QuatRotation = FQuat(TempRotation);
	Rotor->AddLocalRotation(QuatRotation, false, 0, ETeleportType::None);
	if (Break)
		ApplyBreak();
	else
		RotateRotor();
	
}

void ACubeJoystickTest::RotateRotor()
{
	PropellorRotation += RotorTime;
}
void ACubeJoystickTest::ApplyBreak()
{

	PropellorRotation -= RotorTime * 2;

}

void ACubeJoystickTest::PitchUp()
{
	JoystickRotation.Y -= 10;
}
void ACubeJoystickTest::PitchDown()
{
	JoystickRotation.Y += 10;
}
void ACubeJoystickTest::YawRight()
{
	JoystickRotation.Z += 10;
}
void ACubeJoystickTest::YawLeft()
{
	JoystickRotation.Z -= 10;
}
void ACubeJoystickTest::RollRight()
{
	JoystickRotation.X -= 10;
}
void ACubeJoystickTest::RollLeft()
{
	JoystickRotation.X += 10;
}