// Fill out your copyright notice in the Description page of Project Settings.


#include "ApacheJoystick.h"
#include "B_Apache.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Transform.h"
// Sets default values for this component's properties
UApacheJoystick::UApacheJoystick()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UApacheJoystick::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UApacheJoystick::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	JoystickRotation.X = FMath::Clamp(JoystickRotation.X, -90.0f, 90.0f);
	JoystickRotation.Y = FMath::Clamp(JoystickRotation.Y, -90.0f, 90.0f);
	JoystickRotation.Z = FMath::Clamp(JoystickRotation.Z, -90.0f, 90.0f);

	ApacheRotation = JoystickRotation * Multiplier;
	
	Apache->Body->AddTorqueInDegrees(JoystickRotation );
	
//	JoystickRotation = FMath::Lerp(JoystickRotation, FVector(0,0,0), DeltaTime);

}

