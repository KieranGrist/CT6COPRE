// Fill out your copyright notice in the Description page of Project Settings.


#include "Hover.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Public/DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"

// Sets default values for this component's properties
UHover::UHover()
{
	


	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
void UHover::IncreaseThrust()
{
	Thrust += 0.01f;
}
void UHover::DecreaseThrust()
{
	Thrust += 0.01f;
}
// Called when the game starts
void UHover::BeginPlay()
{
	Super::BeginPlay();
	TArray< UPrimitiveComponent*> Array;
	Cube->GetComponents(Array);
	PrimComp = Array[0];
	// ...
	
}


// Called every frame
void UHover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Thrust = FMath::Clamp(Thrust, 0.0f, 1.0f);




	Power = Thrust * Multiplier;
	if (Cube != NULL || Cube != nullptr)
	{

		PrimComp	->AddForce(FVector(0,0, Power));
		
	}



	// ...
}

