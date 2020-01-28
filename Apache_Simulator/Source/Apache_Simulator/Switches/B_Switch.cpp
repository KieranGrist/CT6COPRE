// Fill out your copyright notice in the Description page of Project Settings.


#include "B_Switch.h"

// Sets default values for this component's properties
UB_Switch::UB_Switch()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UB_Switch::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UB_Switch::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UB_Switch::ActionWhenOn()
{
}

void UB_Switch::ActionWhenOff()
{
}

