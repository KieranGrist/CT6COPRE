// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "Helicopter Logic/ApacheEngine.h"
#include "Helicopter Logic/ApacheGun.h"
#include "Helicopter Logic/ApacheRotor.h"
#include "Cockpit.h"
#include "B_Apache.generated.h"

UCLASS()
class APACHE_SIMULATOR_API AB_Apache : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AB_Apache();
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UApacheEngine* RightEngine;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UApacheEngine* LeftEngine;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UCockpit* Cockpit;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UApacheRotor* MainRotor;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
	UApacheGun* ChainGun;


	UPROPERTY(EditAnywhere, Category = "Apache Mesh")

		UStaticMeshComponent* ApacheBody;
	UPROPERTY(EditAnywhere, Category = "Apache Mesh")
		UStaticMeshComponent* Rotor;

	UPROPERTY(EditAnywhere, Category = "Apache Mesh")
		UStaticMeshComponent* GunnerDoor;
	UPROPERTY(EditAnywhere, Category = "Apache Mesh")
		UStaticMeshComponent* PilotDoor;
	UPROPERTY(EditAnywhere, Category = "Apache Mesh")
		UStaticMeshComponent* Window;

	UPROPERTY(EditAnywhere, Category = "Apache Mesh")
		UStaticMeshComponent* Gun;

	UPROPERTY(EditAnywhere, Category = "Apache Mesh")
	UStaticMeshComponent* FlightStick;

	UPROPERTY(EditAnywhere, Category = "Apache Mesh")
	UStaticMeshComponent* Collective;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void PitchUp();
	void PitchDown();
	void YawRight();
	void YawLeft();
	void RollRight();
	void RollLeft();
	void CollectiveRaise();
	void CollectiveLower();
	void LeftEngineSwitchToggle();
	void RightEngineSwitchToggle();
	void RotorBreakToggle();
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UCameraComponent* OurCamera;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
