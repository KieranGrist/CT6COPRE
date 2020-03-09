// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cockpit.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "Helicopter Logic/ApacheRotor.h"
#include "Components/PrimitiveComponent.h"
#include "Helicopter Logic/FlightPhysics.h"
#include "GameFramework/Character.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "B_Apache.generated.h"

UCLASS()
class APACHE_SIMULATOR_API AB_Apache : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AB_Apache();
	UPROPERTY(EditAnywhere)
	UFlightPhysics * FlightPhysics;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UApacheEngine* RightEngine;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UApacheEngine* LeftEngine;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UCockpit* Cockpit;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UApacheRotor* MainRotor;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UCameraComponent* OurCamera;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UStaticMeshComponent* Body;
	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UStaticMeshComponent* MainRotorStaticMesh;

	UPROPERTY(EditAnywhere, Category = "Apache Helicopter")
		UStaticMeshComponent* Tail;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
