// Fill out your copyright notice in the Description page of Project Settings.


#include "ApacheEngine.h"

// Sets default values for this component's properties
UApacheEngine::UApacheEngine()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	// ...
}


// Called when the game starts
void UApacheEngine::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UApacheEngine::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Power = FMath::Clamp(Power, 0.0f, 50.0f);

	if (IsOn)
		EngineOn();
	else
		EngineOff();
}

void UApacheEngine::EngineOn()
{
	
	Power += 0.025f;
}
void UApacheEngine::EngineOff()
{
	Power -= 0.08f;
}
