// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Switches/EngineSwitch.h"
#include "Switches/RotorBreakSwitch.h"
#include "GameFramework/Actor.h"
#include "B_Apache.h"
#include "Cockpit.generated.h"

UCLASS()
class APACHE_SIMULATOR_API ACockpit : public AActor
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere)
		AB_Apache* Apache;
	// Sets default values for this actor's properties
	ACockpit();
	UPROPERTY(EditAnywhere, Category = "Pilot")
	UEngineSwitch* LeftEngineSwitch;
	UPROPERTY(EditAnywhere, Category = "Pilot")
	UEngineSwitch* RightEngineSwitch;
	UPROPERTY(EditAnywhere, Category = "Pilot")
		URotorBreakSwitch* RotorBreakSwitch;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
