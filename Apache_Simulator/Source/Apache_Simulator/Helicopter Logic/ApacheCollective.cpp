// Fill out your copyright notice in the Description page of Project Settings.
#include "ApacheCollective.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "B_Apache.h"

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
	Power = FMath::Clamp(Power, 0.0f, 100.0f);

	Thrust = Collective * 100;
	Collective = FMath::Clamp(Thrust, 0.0F, Power);







	Collective = Apache->Collective->GetRelativeTransform().GetRotation().Euler().Y ;	
	Collective = (-(Collective - 50)) * 0.025f;



	PowerToApply = 0;
	PowerToApply = Thrust;
	PowerToApply *= Multiplier;
	PowerToApply *= DeltaTime;



	if (Apache->MainRotor->PropellorRotation > 6)
	{
		Apache->ApacheBody->AddForce(FVector(Apache->Rotor->GetUpVector() * PowerToApply));

	}


}

