// Fill out your copyright notice in the Description page of Project Settings.


#include "Cockpit.h"
#include "Switches/RotorBreakSwitch.h"
#include "B_Apache.h"
#include"Switches/EngineSwitch.h"
// Sets default values
ACockpit::ACockpit()
{

	RotorBreakSwitch = CreateDefaultSubobject<URotorBreakSwitch>("RotorBreakSwitch");
	RightEngineSwitch = CreateDefaultSubobject<UEngineSwitch>("RightEngineSwitch");
	LeftEngineSwitch = CreateDefaultSubobject<UEngineSwitch>("LeftEngineSwitch");
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	if (Apache)
		if (Apache->RightEngine)
			RightEngineSwitch->ApacheEngine = Apache->RightEngine;

	if (Apache)
		if (Apache->LeftEngine)
			LeftEngineSwitch->ApacheEngine = Apache->LeftEngine;


}

// Called when the game starts or when spawned
void ACockpit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACockpit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

