// Fill out your copyright notice in the Description page of Project Settings.


#include "Physics.h"
#include "Switches/RotorBreakSwitch.h"
#include "Helicopter Logic/ApacheCollective.h"
#include"Switches/EngineSwitch.h"
#include "Engine/World.h"
#include "Components/PrimitiveComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Helicopter Logic/ApacheJoystick.h"
#include "B_Apache.h"
// Sets default values
APhysics::APhysics()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

		 SceneCube=  CreateDefaultSubobject<USceneComponent>("SceneCube");;

		 Cube = CreateDefaultSubobject<UStaticMeshComponent>("Cube");;
		 FAttachmentTransformRules ARules(EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, EAttachmentRule::KeepRelative, false);
		 Cube->AttachToComponent(SceneCube, ARules);

		 Collective =0;

		 Power =0;

		 Thrust = 0;

		 PowerToApply = 0;

		 Speed =0;
		 Multiplier = 0;
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
	
	Power = FMath::Clamp(Power, 0.0f, 100.0f);
	Collective = FMath::Clamp(Collective, 0.0f, 1.0f);
	Thrust = Collective * 100;
	Thrust = FMath::Clamp(Thrust, 0.0F, Power);


	//Collective = FMath::Lerp(Collective, .515f, DeltaTime);

//0 = -0.5, 50 = 0, 100 = 0.5 

	 PowerToApply = 0;
	 PowerToApply = Thrust;
	 PowerToApply *= Multiplier;
	 PowerToApply *= DeltaTime;



	//	Collective = FMath::Lerp(Collective, .515f, DeltaTime);
	


		Cube->AddForce(FVector(GetActorUpVector() * PowerToApply));

		this->SetActorLocation(Cube->GetComponentLocation());
		this->SetActorRotation(Cube->GetComponentQuat());
		if (!PhysicsRef)
		{
			TArray< UPrimitiveComponent*> Array;
			GetComponents(Array);
			if (Array[0])
				PhysicsRef = Array[0];
		}
		if (PhysicsRef)
			Speed = PhysicsRef->GetComponentVelocity().Size();
}

