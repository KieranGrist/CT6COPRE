// Fill out your copyright notice in the Description page of Project Settings.


#include "HelicopterLoadout.h"

// Sets default values for this component's properties
UHelicopterLoadout::UHelicopterLoadout()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	CreateSlots();
	switch (HelicopterLoadout)
	{
	case CAS:
		LoadCAS();
		break;
	case AT:
		LoadAT();
		break;
	case MR:
		LoadMR();
		break;
	default:
		break;
	}
	// ...
}


// Called when the game starts
void UHelicopterLoadout::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UHelicopterLoadout::CreateSlots()
{

}

void UHelicopterLoadout::CreatePylons()
{
}

void UHelicopterLoadout::LoadCAS()
{
}

void UHelicopterLoadout::LoadAT()
{
}

void UHelicopterLoadout::LoadMR()
{
}


// Called every frame
void UHelicopterLoadout::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

}

