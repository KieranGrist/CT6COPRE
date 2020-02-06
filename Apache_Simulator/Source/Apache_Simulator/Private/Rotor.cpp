// Fill out your copyright notice in the Description page of Project Settings.


#include "Rotor.h"
#include "Helicopter Logic/ApacheRotor.h"
// Sets default values
ARotor::ARotor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ApacheRotor = CreateDefaultSubobject<UApacheRotor>("ApacheRotor");
}

// Called when the game starts or when spawned
void ARotor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

