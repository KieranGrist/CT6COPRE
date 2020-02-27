// Fill out your copyright notice in the Description page of Project Settings.


#include "AMySpawner.h"
#include "Helicopter Logic/ApacheRotor.h"
#include "Engine/World.h"
// Sets default values
AAMySpawner::AAMySpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
// Called when the game starts or when spawned
void AAMySpawner::BeginPlay()
{
	Super::BeginPlay();
	FVector NewLocation = GetActorLocation() + FVector(0.f, 0.f, 300.f);

	// Spawn the new actor (Using GetClass() instead of AMySpawner so that if someone derives a new class  
	// from AMySpawner we spawn an instance of that class instead)  
	auto NewActor = GetWorld()->SpawnActor<UApacheRotor>(ApacheRotor->GetClass(), NewLocation, FRotator::ZeroRotator);
}

// Called every frame
void AAMySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

