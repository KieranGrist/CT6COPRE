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
	Collective = FMath::Clamp(Collective, 0.0f, 1.0f);
	Thrust = Collective * 100;
	Thrust = FMath::Clamp(Thrust, 0.0F, Power);


		//Collective = FMath::Lerp(Collective, .515f, DeltaTime);

	//0 = -0.5, 50 = 0, 100 = 0.5 

	Stage1 = PowerToApply = 0;
	Stage2 = PowerToApply = Thrust - Power * .5f;
	Stage3=  PowerToApply *= Multiplier;
	Stage4= PowerToApply *= DeltaTime;
	if (Power < 2)
		NoPower(DeltaTime);
	
	if (Apache->Rotor->ApacheRotor->PropellorRotation > 6 )
	{
		Apache->Body->AddForce(FVector(Apache->GetActorUpVector() * PowerToApply));
		Collective = FMath::Lerp(Collective, .515f, DeltaTime);
	}
	else 
		NoPower(DeltaTime);
	
	if (!PhysicsRef)
	{
		TArray< UPrimitiveComponent*> Array;
		Apache->GetComponents(Array);
		if (Array[0])
			PhysicsRef = Array[0];
	}
}

void UApacheCollective::NoPower(float DeltaTime)
{

		Collective = FMath::Lerp(Collective, 0.0f, DeltaTime);
		PowerToApply = ((-100 * Multiplier)) * DeltaTime;
		if (Apache->Body->GetRelativeTransform().GetLocation().Z < 31)
		Apache->Body->AddForce(FVector(Apache->GetActorUpVector() * PowerToApply));
}