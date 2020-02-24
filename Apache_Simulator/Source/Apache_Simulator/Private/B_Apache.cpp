// Fill out your copyright notice in the Description page of Project Settings.


#include "B_Apache.h"
#include "Engine/EngineTypes.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "Helicopter Logic/ApacheRotor.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
// Sets default values
AB_Apache::AB_Apache()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	Body = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	Tail = CreateDefaultSubobject<UStaticMeshComponent>("Tail");
	MainRotor = CreateDefaultSubobject<UApacheRotor>("MainRotor");
	TailRotor = CreateDefaultSubobject<UApacheRotor>("TailRotor");
	Cockpit = CreateDefaultSubobject<UCockpit>("Cockpit");



	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurCamera->SetRelativeLocation(FVector(-250.0f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	FAttachmentTransformRules ARules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative,false);
	Body->AttachToComponent(RootComponent, ARules);
	Tail->AttachToComponent(Body, ARules);
	OurCamera->SetupAttachment(Body);
	RightEngine = CreateDefaultSubobject<UApacheEngine>("RightEngine");
	LeftEngine = CreateDefaultSubobject<UApacheEngine>("LeftEngine");



	
}

// Called when the game starts or when spawned
void AB_Apache::BeginPlay()
{
	Cockpit->Apache = this;
	Cockpit->Collective->Apache = this;
	MainRotor->Apache = this;
	Super::BeginPlay();
	FAttachmentTransformRules ARules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	MainRotor->RootComponent->AttachToComponent(Body, ARules);
	TailRotor->RootComponent->AttachToComponent(Body, ARules);
}

// Called every frame
void AB_Apache::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Body->SetLinearDamping(LinerDampening);
	this->SetActorLocation(Body->GetComponentLocation());
	this->SetActorRotation(Body->GetComponentQuat());	
}

