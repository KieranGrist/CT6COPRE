// Fill out your copyright notice in the Description page of Project Settings.

	#pragma once


#include "CoreMinimal.h"
#include "Switches/RotorBreakSwitch.h"
#include"Switches/EngineSwitch.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "Cockpit.generated.h"
class AB_Apache;
UCLASS()
class APACHE_SIMULATOR_API UCockpit : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		AB_Apache* Apache;
	// Sets default values for this actor's properties
	UCockpit();
	UPROPERTY(EditAnywhere, Category = "Pilot")
		UEngineSwitch* LeftEngineSwitch;
	UPROPERTY(EditAnywhere, Category = "Pilot")
		UEngineSwitch* RightEngineSwitch;
	UPROPERTY(EditAnywhere, Category = "Pilot")
		URotorBreakSwitch* RotorBreakSwitch;
	UPROPERTY(EditAnywhere)
		float Speed = 0;
	UPROPERTY(EditAnywhere)
		float Height = 0;
	UPrimitiveComponent* PhysicsRef; 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

};