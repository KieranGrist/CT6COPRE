// Fill out your copyright notice in the Description page of Project Settings.


#include "B_Apache.h"
#include "Engine/EngineTypes.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
// Sets default values
AB_Apache::AB_Apache()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FlightPhysics = CreateDefaultSubobject<UFlightPhysics>("FlightPhysics");
	FlightPhysics->Apache = this;
	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

	Body = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	Tail = CreateDefaultSubobject<UStaticMeshComponent>("Tail");

	Tail->SetRelativeLocation(FVector(-854.415527f, 0, 81.176666f));
	MainRotorStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("MainRotorStaticMesh");

	MainRotor = CreateDefaultSubobject<UApacheRotor>("MainRotor");
	MainRotor->Rotor = MainRotorStaticMesh;
	Cockpit = CreateDefaultSubobject<UCockpit>("Cockpit");

OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	FAttachmentTransformRules ARules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
	FAttachmentTransformRules BRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
	Body->AttachToComponent(RootComponent, BRules);
	MainRotorStaticMesh->AttachToComponent(Body,ARules);
	Tail->AttachToComponent(Body, BRules);
	MainRotorStaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	OurCamera->SetupAttachment(Body);
	RightEngine = CreateDefaultSubobject<UApacheEngine>("RightEngine");
	LeftEngine = CreateDefaultSubobject<UApacheEngine>("LeftEngine");
}

// Called when the game starts or when spawned
void AB_Apache::BeginPlay()
{	
	Super::BeginPlay();
	Cockpit->Apache = this;
	Cockpit->Collective->Apache = this;
	Cockpit->Joystick->Apache = this;
	MainRotor->Apache = this;
}

// Called every frame
void AB_Apache::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->SetActorLocation(Body->GetComponentLocation());
	this->SetActorRotation(Body->GetComponentQuat());	
}

