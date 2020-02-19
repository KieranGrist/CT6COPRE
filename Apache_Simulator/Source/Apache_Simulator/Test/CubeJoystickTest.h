// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeJoystickTest.generated.h"

UCLASS()
class APACHE_SIMULATOR_API ACubeJoystickTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeJoystickTest();
	UPROPERTY(EditAnywhere)
		FVector JoystickRotation;
	UPROPERTY(EditAnywhere)
		float Multiplier;
	UPROPERTY(EditAnywhere)
		FVector ApacheRotation;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
