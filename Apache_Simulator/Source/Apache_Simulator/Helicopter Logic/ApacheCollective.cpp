// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "ApacheCollective.h"

// Sets default values for this component's properties
UApacheCollective::UApacheCollective()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UApacheCollective::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UApacheCollective::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Power = Apache->LeftEngine->Power + Apache->RightEngine->Power;
	Collective = FMath::Clamp(Collective, 0.0f, 1.0f);
	Thrust = Collective * 100;

	Thrust = FMath::Clamp(Thrust, 0.0F, Power);


	//0 = -0.5, 50 = 0, 100 = 0.5 


	PowerToApply = Thrust - Power * .5f;
	PowerToApply *= Multiplier;


	TArray< UPrimitiveComponent*> Array;
	Apache->GetComponents(Array);
	if (Array[0])
		Array[0]->AddForce(FVector(Apache->GetActorUpVector() * PowerToApply));
}

