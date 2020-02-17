// Fill out your copyright notice in the Description page of Project Settings.


#include "Physics.h"

// Sets default values
APhysics::APhysics()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APhysics::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhysics::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

