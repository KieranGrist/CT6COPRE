// Fill out your copyright notice in the Description page of Project Settings.


#include "B_Apache.h"
#include "Engine/EngineTypes.h"
// Sets default values
AB_Apache::AB_Apache()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Apache_AH64 = CreateDefaultSubobject<USceneComponent>("Apache_AH64");
	Body = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	Tail = CreateDefaultSubobject<UStaticMeshComponent>("Tail");
	MainRotor = CreateDefaultSubobject<ARotor>("MainRotor");
	TailRotor = CreateDefaultSubobject<ARotor>("TailRotor");
	Cockpit = CreateDefaultSubobject<ACockpit>("Cockpit");
	
	FAttachmentTransformRules ARules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative,false);
	Body->AttachToComponent(Apache_AH64, ARules);
	Tail->AttachToComponent(Body, ARules);
	RightEngine = CreateDefaultSubobject<UApacheEngine>("RightEngine");
	LeftEngine = CreateDefaultSubobject<UApacheEngine>("LeftEngine");


	Cockpit->Apache = this;
	Cockpit->Collective->Apache = this;
	MainRotor->ApacheRotor->Apache = this;
	
}

// Called when the game starts or when spawned
void AB_Apache::BeginPlay()
{

	Super::BeginPlay();
	FAttachmentTransformRules ARules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, false);
	MainRotor->AttachToComponent(Body, ARules);
	TailRotor->AttachToComponent(Body, ARules);
	Body->SetSimulatePhysics(true);


}

// Called every frame
void AB_Apache::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Body->SetLinearDamping(LinerDampening);
	this->SetActorLocation(Body->GetComponentLocation());
	this->SetActorRotation(Body->GetComponentQuat());	
}

