// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "B_Apache.h"
#include "Components/ActorComponent.h"
#include "Rotor.h"
#include "ApacheEngine.h"
#include "Cockpit.h"
#include "ApacheRotor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APACHE_SIMULATOR_API UApacheRotor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UApacheRotor();
	UPROPERTY(EditAnywhere)
		ARotor* Rotor;


	UPROPERTY(EditAnywhere)
		ACockpit * Cockpit;
	UPROPERTY(EditAnywhere, Category = "Rotor Properties")
		float PropellorRotation;
	
	UPROPERTY(EditAnywhere, Category = "Rotor Properties")
		float RotorTime;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void RotateRotor();

	void ApplyBreak();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
