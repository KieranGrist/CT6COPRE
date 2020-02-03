// Fill out your copyright notice in the Description page of Project Settings.


#include "ApacheRotor.h"

// Sets default values for this component's properties
UApacheRotor::UApacheRotor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UApacheRotor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
void UApacheRotor::RotateRotor()
{

	PropellorRotation += RotorTime;

}
void UApacheRotor::ApplyBreak()
{

	PropellorRotation -= RotorTime *2;

}


// Called every frame
void UApacheRotor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	PropellorRotation = FMath::Clamp(PropellorRotation, 0.0f, 7.0f);
	FRotator  TempRotation = FRotator(0, PropellorRotation, 0);
	FQuat QuatRotation = FQuat(TempRotation);
	Rotor->AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);
	if (Cockpit->LeftEngineSwitch->IsOn && Cockpit->RotorBreakSwitch->IsOn == false)
		RotateRotor();

	if (Cockpit->RightEngineSwitch->IsOn && Cockpit->RotorBreakSwitch->IsOn == false)
		RotateRotor();
	if (Cockpit->RightEngineSwitch->IsOn && Cockpit->LeftEngineSwitch->IsOn == false || Cockpit->RightEngineSwitch->IsOn == false && Cockpit->LeftEngineSwitch->IsOn)
		PropellorRotation -=  RotorTime *0.9f;
	
	if (Cockpit->RotorBreakSwitch->IsOn)
		ApplyBreak();
}

