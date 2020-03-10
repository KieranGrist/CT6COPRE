// Fill out your copyright notice in the Description page of Project Settings.


#include "B_Apache.h"
#include "Engine/EngineTypes.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
// Sets default values
AB_Apache::AB_Apache()
{
	AutoPossessPlayer = EAutoReceiveInput::Player0;
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	FAttachmentTransformRules ARules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
	FAttachmentTransformRules BRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");

ApacheBody = CreateDefaultSubobject<UStaticMeshComponent>("ApacheBody");
ApacheBody->AttachToComponent(RootComponent, BRules);

 Rotor = CreateDefaultSubobject<UStaticMeshComponent>("Rotor");
 Rotor->AttachToComponent(ApacheBody, ARules);
 Rotor->SetRelativeLocation(FVector(-69.173035f, 0, 503.540344f));

 GunnerDoor = CreateDefaultSubobject<UStaticMeshComponent>("GunnerDoor");	
 GunnerDoor->AttachToComponent(ApacheBody, ARules);

PilotDoor = CreateDefaultSubobject<UStaticMeshComponent>("PilotDoor");
PilotDoor->AttachToComponent(ApacheBody, ARules);

Window = CreateDefaultSubobject<UStaticMeshComponent>("Window");
Window->AttachToComponent(ApacheBody, ARules);

Gun = CreateDefaultSubobject<UStaticMeshComponent>("Gun");
Gun->AttachToComponent(ApacheBody, ARules);
Gun->SetRelativeLocation(FVector(440.466095f, 0, 108.680374f));

 FlightStick = CreateDefaultSubobject<UStaticMeshComponent>("FlightStick");
 FlightStick->AttachToComponent(ApacheBody, ARules);
 FlightStick->SetRelativeLocation(FVector(278.58075f, 0, 237.448517f));

 Collective = CreateDefaultSubobject<UStaticMeshComponent>("Collective");
 Collective->AttachToComponent(ApacheBody, ARules);

	Cockpit = CreateDefaultSubobject<UCockpit>("Cockpit");
	Cockpit->Collective->Apache = this;
	Cockpit->Joystick->Apache = this;
	Cockpit->Apache = this;

	RightEngine = CreateDefaultSubobject<UApacheEngine>("RightEngine");
	LeftEngine = CreateDefaultSubobject<UApacheEngine>("LeftEngine");
	Cockpit->RightEngineSwitch->ApacheEngine = RightEngine;
	Cockpit->LeftEngineSwitch->ApacheEngine = LeftEngine;


	MainRotor = CreateDefaultSubobject<UApacheRotor>("MainRotor");
	MainRotor->Apache = this;

	ChainGun = CreateDefaultSubobject<UApacheGun>("ChainGun");

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));

	OurCamera->SetupAttachment(ApacheBody);
	OurCamera->SetRelativeLocation(FVector(-2332.526855f, 0.0f, 819.872986));
	OurCamera->SetRelativeRotation(FRotator(0, -13.618747f, 0));
}

// Called when the game starts or when spawned
void AB_Apache::BeginPlay()
{
	Super::BeginPlay();
	Cockpit->Collective->Apache = this;
	Cockpit->Joystick->Apache = this;
	Cockpit->Apache = this;
	Cockpit->RightEngineSwitch->ApacheEngine = RightEngine;
	Cockpit->LeftEngineSwitch->ApacheEngine = LeftEngine;
	MainRotor->Apache = this;

}


void AB_Apache::SetupPlayerInputComponent(UInputComponent* InputComponent)
{
}

// Called every frame
void AB_Apache::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->SetActorLocation(ApacheBody->GetComponentLocation());
	this->SetActorRotation(ApacheBody->GetComponentQuat());
}

