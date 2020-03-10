// Fill out your copyright notice in the Description page of Project Settings.


#include "Hydra_Rockets.h"

// Sets default values for this component's properties
UHydra_Rockets::UHydra_Rockets()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHydra_Rockets::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHydra_Rockets::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

