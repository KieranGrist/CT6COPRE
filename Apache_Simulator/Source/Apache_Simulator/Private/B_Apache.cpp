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




	Cockpit = CreateDefaultSubobject<UCockpit>("Cockpit");

	Cockpit->Apache = this;

	RightEngine = CreateDefaultSubobject<UApacheEngine>("RightEngine");
	LeftEngine = CreateDefaultSubobject<UApacheEngine>("LeftEngine");
	Cockpit->RightEngineSwitch->ApacheEngine = RightEngine;
	Cockpit->LeftEngineSwitch->ApacheEngine = LeftEngine;


	MainRotor = CreateDefaultSubobject<UApacheRotor>("MainRotor");
	MainRotor->Apache = this;

	ChainGun = CreateDefaultSubobject<UApacheGun>("ChainGun");
}

// Called when the game starts or when spawned
void AB_Apache::BeginPlay()
{
	Super::BeginPlay();
	Cockpit->Apache = this;
	Cockpit->RightEngineSwitch->ApacheEngine = RightEngine;
	Cockpit->LeftEngineSwitch->ApacheEngine = LeftEngine;
	MainRotor->Apache = this;

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

