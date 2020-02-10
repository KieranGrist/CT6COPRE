// Fill out your copyright notice in the Description page of Project Settings.


#include "Rotor.h"
#include "Helicopter Logic/ApacheRotor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ARotor::ARotor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RotorSceneComponent = CreateDefaultSubobject<USceneComponent>("RotorSceneComponent");
	RotorMesh = CreateDefaultSubobject<UStaticMeshComponent>("RotorMesh");
	ApacheRotor = CreateDefaultSubobject<UApacheRotor>("ApacheRotor");
	ApacheRotor->Rotor = this;

	FAttachmentTransformRules ARules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
	RotorMesh->AttachToComponent(RotorSceneComponent, ARules);
}

// Called when the game starts or when spawned
void ARotor::BeginPlay()
{
	ApacheRotor->Rotor = this;
	Super::BeginPlay();
	RotorMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

// Called every frame
void ARotor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

