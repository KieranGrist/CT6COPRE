// Fill out your copyright notice in the Description page of Project Settings.


#include "EngineSwitch.h"

// Sets default values for this component's properties
UEngineSwitch::UEngineSwitch()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEngineSwitch::BeginPlay()
{
	Super::BeginPlay();
	IsOn = false;
	// ...
	
}


// Called every frame
void UEngineSwitch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (IsOn)
		ActionWhenOn();
	else
		ActionWhenOff();
	// ...
}

void UEngineSwitch::ActionWhenOn()
{
	ApacheEngine->IsOn = true;

}

void UEngineSwitch::ActionWhenOff()
{
	ApacheEngine->IsOn = false;
}

