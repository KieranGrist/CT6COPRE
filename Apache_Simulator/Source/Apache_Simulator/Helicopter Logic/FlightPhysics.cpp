// Fill out your copyright notice in the Description page of Project Settings.


#include "FlightPhysics.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "B_Apache.h"
// Sets default values for this component's properties
UFlightPhysics::UFlightPhysics()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFlightPhysics::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UFlightPhysics::AddForce(FVector Force)
{

	auto Acceleration = Force / 5165;
	Velocity += Acceleration * GetDelta();
}
float UFlightPhysics::GetDelta()

{
	return Delta;
}
// Called every frame
void UFlightPhysics::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Velocity += Gravity * 5165;
	Velocity /= 2;
	Delta = DeltaTime;
	Location = Apache->GetActorLocation();

	if (Location.Z < -100)
	{
		Location =FVector(Location.X, Location.Y, 500);
		Location = FVector(0, 0, 0);
	}

	Location += Velocity * Delta;
	Apache->SetActorLocation(Location);
	

}

