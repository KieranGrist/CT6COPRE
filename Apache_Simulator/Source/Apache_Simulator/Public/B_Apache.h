// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Cockpit.h"
#include "Components/SceneComponent.h"
#include "Rotor.h"
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
		UStaticMeshComponent* Body;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Tail;

	UPROPERTY(EditAnywhere)
		ACockpit* Cockpit;
	UPROPERTY(EditAnywhere)
	ARotor* MainRotor;
	UPROPERTY(EditAnywhere)
		ARotor* TailRotor;
	UPROPERTY(EditAnywhere)
		UApacheEngine* LeftEngine;
	UPROPERTY(EditAnywhere)
		UApacheEngine* RightEngine;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
