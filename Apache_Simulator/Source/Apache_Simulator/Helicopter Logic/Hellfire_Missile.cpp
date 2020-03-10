// Fill out your copyright notice in the Description page of Project Settings.


#include "Hellfire_Missile.h"

// Sets default values for this component's properties
UHellfire_Missile::UHellfire_Missile()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHellfire_Missile::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHellfire_Missile::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

