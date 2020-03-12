// Fill out your copyright notice in the Description page of Project Settings.


#include "B_Apache.h"
#include "Components/ActorComponent.h"
#include "Components/InputComponent.h"
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
 FAttachmentTransformRules CRules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
 Rotor->AttachToComponent(ApacheBody, CRules);
 Rotor->SetRelativeLocation(FVector(-69.173035f, 0, 503.540344f));
 Rotor->SetRelativeRotation(FRotator(0, 0, 0));


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
void AB_Apache::PitchUp()
{
	Cockpit->Joystick-> JoystickRotation.Y -= 10;
}
void AB_Apache::PitchDown()
{
	Cockpit->Joystick->JoystickRotation.Y += 10;
}
void AB_Apache::YawRight()
{
	Cockpit->Joystick->JoystickRotation.Z += 10;
}
void AB_Apache::YawLeft()
{
	Cockpit->Joystick->JoystickRotation.Z -= 10;
}
void AB_Apache::RollRight()
{
	Cockpit->Joystick->JoystickRotation.X -= 10;
}
void AB_Apache::RollLeft()
{
	Cockpit->Joystick->JoystickRotation.X += 10;
}


void AB_Apache::CollectiveRaise()
{
	Cockpit->Collective->Collective += .01f;
}
void AB_Apache::CollectiveLower()
{
	Cockpit->Collective->Collective -= .01f;
}





void AB_Apache::LeftEngineSwitchToggle()
{
	Cockpit->LeftEngineSwitch->IsOn = !Cockpit->LeftEngineSwitch->IsOn;
}
void AB_Apache::RightEngineSwitchToggle()
{

		Cockpit->RightEngineSwitch->IsOn = !Cockpit->RightEngineSwitch->IsOn;
}

void AB_Apache::RotorBreakToggle()
{
	Cockpit->RotorBreakSwitch->IsOn = !Cockpit->RotorBreakSwitch->IsOn;
}


void AB_Apache::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("Pitch Up", IE_Pressed, this, &AB_Apache::PitchUp);
	InputComponent->BindAction("Pitch Down", IE_Pressed, this, &AB_Apache::PitchDown);
	InputComponent->BindAction("Yaw Right", IE_Pressed, this, &AB_Apache::YawRight);
	InputComponent->BindAction("Yaw Left", IE_Pressed, this, &AB_Apache::YawLeft);
	InputComponent->BindAction("Roll Right", IE_Pressed, this, &AB_Apache::RollRight);
	InputComponent->BindAction("Roll Left", IE_Pressed, this, &AB_Apache::RollLeft);

	InputComponent->BindAction("Collective Raise", IE_Pressed, this, &AB_Apache::CollectiveRaise);
	InputComponent->BindAction("Collective Lower", IE_Pressed, this, &AB_Apache::CollectiveLower);


	InputComponent->BindAction("LeftEngineSwitchToggle", IE_Pressed, this, &AB_Apache::LeftEngineSwitchToggle);
	InputComponent->BindAction("RightEngineSwitchToggle", IE_Pressed, this, &AB_Apache::RightEngineSwitchToggle);
	InputComponent->BindAction("RotorBreakToggle", IE_Pressed, this, &AB_Apache::RotorBreakToggle);

}

// Called every frame
void AB_Apache::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	this->SetActorLocation(ApacheBody->GetComponentLocation());
	this->SetActorRotation(ApacheBody->GetComponentQuat());
}

