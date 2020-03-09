// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ApacheJoystick.generated.h"

class AB_Apache;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APACHE_SIMULATOR_API UApacheJoystick : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UApacheJoystick();
	UPROPERTY(EditAnywhere)
	FVector JoystickRotation;
	UPROPERTY(EditAnywhere)
	float Multiplier; 
	UPROPERTY(EditAnywhere)
	FVector ApacheRotation;
	UPROPERTY(EditAnywhere)
		AB_Apache* Apache;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void PitchUp();

	void PitchDown();

	void YawRight();

	void YawLeft();

	void RollRight();

	void RollLeft();
		
};
