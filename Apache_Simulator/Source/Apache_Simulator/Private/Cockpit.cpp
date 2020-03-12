// Fill out your copyright notice in the Description page of Project Settings.


#include "Cockpit.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "Containers/Array.h"
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
}

// Called when the game starts or when spawned
void UCockpit::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UCockpit::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!PhysicsRef)
	{
		TArray< UPrimitiveComponent*> Array;
		Apache->GetComponents(Array);
		if (Array[1])
			PhysicsRef = Array[1];
	}
	auto velocity = PhysicsRef->GetComponentVelocity();
	Speed = PhysicsRef->GetComponentVelocity().Size();

}

