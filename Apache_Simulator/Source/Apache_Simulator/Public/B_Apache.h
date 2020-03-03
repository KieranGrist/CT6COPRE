// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cockpit.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
//#include "Helicopter Logic/ApacheRotor.h"
#include "Components/PrimitiveComponent.h"
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
	UCameraComponent* OurCamera;
	UPROPERTY(EditAnywhere, Category = "Main Body")
		UStaticMeshComponent* Body;
//	UPROPERTY(EditAnywhere, Category = "Main Body")
//		UApacheRotor* MainRotor;
	UPROPERTY(EditAnywhere, Category = "Main Body")
		UStaticMeshComponent* MainRotorStaticMesh;
	UPROPERTY(EditAnywhere, Category = "Main Body")
		ACockpit* Cockpit;
	UPROPERTY(EditAnywhere, Category = "Main Body")
		UApacheEngine* RightEngine;
	UPROPERTY(EditAnywhere, Category = "Main Body")
		UApacheEngine* LeftEngine;


	UPROPERTY(EditAnywhere, Category = "Tail")
		UStaticMeshComponent* Tail;
//	UPROPERTY(EditAnywhere, Category = "Tail")
	//	UApacheRotor* TailRotor;
	UPROPERTY(EditAnywhere, Category = "Tail")
		UStaticMeshComponent* TailRotorStaticMesh;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
