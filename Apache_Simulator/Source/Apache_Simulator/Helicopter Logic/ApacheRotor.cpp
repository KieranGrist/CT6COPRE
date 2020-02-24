// Fill out your copyright notice in the Description page of Project Settings.


#include "ApacheRotor.h"
#include "Components/ActorComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "B_Apache.h"
// Sets default values for this component's properties
UApacheRotor::UApacheRotor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Rotor = CreateDefaultSubobject<UStaticMeshComponent>("Rotor");
	FAttachmentTransformRules ARules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
	Rotor->AttachToComponent(RootComponent,ARules);
	Rotor->SetCollisionEnabled(ECollisionEnabled::NoCollision);
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
	Rotor->AddWorldRotation(QuatRotation, false, 0, ETeleportType::None);
	if (Apache->Cockpit->LeftEngineSwitch->IsOn && Apache->Cockpit->RotorBreakSwitch->IsOn == false)
		RotateRotor();

	if (Apache->Cockpit->RightEngineSwitch->IsOn && Apache->Cockpit->RotorBreakSwitch->IsOn == false)
		RotateRotor();
	if (Apache->Cockpit->RightEngineSwitch->IsOn && Apache->Cockpit->LeftEngineSwitch->IsOn == false || Apache->Cockpit->RightEngineSwitch->IsOn == false && Apache->Cockpit->LeftEngineSwitch->IsOn)
		PropellorRotation -=  RotorTime *0.9f;
	
	if (Apache->Cockpit->RotorBreakSwitch->IsOn)
		ApplyBreak();
}

