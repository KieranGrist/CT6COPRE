// Fill out your copyright notice in the Description page of Project Settings.


#include "Cockpit.h"
#include "B_Apache.h"

// Sets default values
UCockpit::UCockpit()
{
	PrimaryComponentTick.bCanEverTick = true;
	RotorBreakSwitch = CreateDefaultSubobject<URotorBreakSwitch>("RotorBreakSwitch");
	RightEngineSwitch = CreateDefaultSubobject<UEngineSwitch>("RightEngineSwitch");
	LeftEngineSwitch = CreateDefaultSubobject<UEngineSwitch>("LeftEngineSwitch");
	Joystick = CreateDefaultSubobject<UApacheJoystick >("Joystick");
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.


	Collective = CreateDefaultSubobject <UApacheCollective>("Collective");
	Joystick->Apache = Apache;
	Collective->Apache = Apache;
}

// Called when the game starts or when spawned
void UCockpit::BeginPlay()
{
	Super::BeginPlay();
	Joystick->Apache = Apache;
	Collective->Apache = Apache;
	RightEngineSwitch->ApacheEngine = Apache->RightEngine;
	LeftEngineSwitch->ApacheEngine = Apache->LeftEngine;
}

// Called every frame
void UCockpit::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

		Speed = Apache->FlightPhysics->Velocity.Size();

	FVector Loc = Apache->GetTransform().GetLocation();
	FRotator Rot = FRotator(Apache->GetTransform().GetRotation());
	FHitResult Hit;
	FVector Start = Loc;
	FVector End = -Apache->GetActorUpVector();
	GetWorld()->LineTraceSingleByChannel(Hit, Loc, End, ECC_Visibility);
	Height = FVector::Distance(Apache->GetTransform().GetLocation(), Hit.Location);
	Height -= 28.685221f;
}

