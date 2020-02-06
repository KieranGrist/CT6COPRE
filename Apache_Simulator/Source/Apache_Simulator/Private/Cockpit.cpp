// Fill out your copyright notice in the Description page of Project Settings.


#include "Cockpit.h"
#include "B_Apache.h"

// Sets default values
ACockpit::ACockpit()
{

	RotorBreakSwitch = CreateDefaultSubobject<URotorBreakSwitch>("RotorBreakSwitch");
	RightEngineSwitch = CreateDefaultSubobject<UEngineSwitch>("RightEngineSwitch");
	LeftEngineSwitch = CreateDefaultSubobject<UEngineSwitch>("LeftEngineSwitch");
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collective = CreateDefaultSubobject <UApacheCollective>("Collective");


}

// Called when the game starts or when spawned
void ACockpit::BeginPlay()
{
	Super::BeginPlay();
	Collective->Apache = Apache;
	if (Apache)
		if (Apache->RightEngine)
			RightEngineSwitch->ApacheEngine = Apache->RightEngine;

	if (Apache)
		if (Apache->LeftEngine)
			LeftEngineSwitch->ApacheEngine = Apache->LeftEngine;
}

// Called every frame
void ACockpit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(Collective->PhysicsRef)
	Speed = Collective->PhysicsRef->GetComponentVelocity().Size();
	
	FVector Loc = Apache->Body->GetComponentTransform().GetLocation();
	FRotator Rot = FRotator(Apache->Body->GetComponentTransform().GetRotation()); 
	FHitResult Hit ;
	FVector Start = Loc;
	FVector End =  -Apache->GetActorUpVector(); 
	GetWorld()->LineTraceSingleByChannel(Hit, Loc, End, ECC_Visibility);
Height =	FVector::Distance(Apache->GetTransform().GetLocation(), Hit.Location);
Height -= 28.685221f;
}

