// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Helicopter")
		UApacheEngine* RightEngine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Helicopter")
		UApacheEngine* LeftEngine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Helicopter")
		UCockpit* Cockpit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Helicopter")
		UApacheRotor* MainRotor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Helicopter")
	UApacheGun* ChainGun;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Mesh")

		UStaticMeshComponent* ApacheBody;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Mesh")
		UStaticMeshComponent* Rotor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Mesh")
		UStaticMeshComponent* GunnerDoor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Mesh")
		UStaticMeshComponent* PilotDoor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Mesh")
		UStaticMeshComponent* Window;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Apache Mesh")
		UStaticMeshComponent* Gun;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void LeftEngineSwitchToggle();
	void RightEngineSwitchToggle();
	void RotorBreakToggle();
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
