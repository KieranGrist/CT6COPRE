// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeJoystickTest.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/LightComponent.h"
#include "Components/SpotLightComponent.h"
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
	Multiplier = 387889.375f;

	// Attach our camera and visible object to our root component. Offset and rotate the camera.
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	Cube->SetupAttachment(RootComponent);
	
}
void ACubeJoystickTest::PitchUp()
{
	JoystickRotation.X+=10;
}
void ACubeJoystickTest::PitchDown()
{
	JoystickRotation.X-=10;
}
void ACubeJoystickTest::YawRight()
{
	JoystickRotation.Y+=10;
}
void ACubeJoystickTest::YawLeft()
{
	JoystickRotation.Y-=10;
}
void ACubeJoystickTest::RollRight()
{
	JoystickRotation.Z+=10;
}
void ACubeJoystickTest::RollLeft()
{
	JoystickRotation.Z-=10;
}
// Called when the game starts or when spawned
void ACubeJoystickTest::BeginPlay()
{

	Super::BeginPlay();

}


void ACubeJoystickTest::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("Pitch Up", IE_Pressed, this, &ACubeJoystickTest::PitchUp);
	InputComponent->BindAction("Pitch Down", IE_Pressed, this, &ACubeJoystickTest::PitchDown);
	InputComponent->BindAction("Yaw Right", IE_Pressed, this, &ACubeJoystickTest::YawRight);
	InputComponent->BindAction("Yaw Left", IE_Pressed, this, &ACubeJoystickTest::YawLeft);
	InputComponent->BindAction("Roll Right", IE_Pressed, this, &ACubeJoystickTest::RollRight);
	InputComponent->BindAction("Roll Left", IE_Pressed, this, &ACubeJoystickTest::RollLeft);
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

}

