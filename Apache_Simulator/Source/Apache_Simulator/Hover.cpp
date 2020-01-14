// Fill out your copyright notice in the Description page of Project Settings.


#include "Hover.h"

// Sets default values for this component's properties
UHover::UHover()
{
	

	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHover::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Thrust = FMath::Clamp(Thrust, 0.0f, 1.0f);

	Power = Thrust * Multiplier;


	AActor* Cube = GetOwner();
	//Cube->AddForce();

	// ...
}

