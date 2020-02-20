// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "CubeJoystickTest.generated.h"

UCLASS()
class APACHE_SIMULATOR_API ACubeJoystickTest : public APawn
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
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Cube;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Gun;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Rotor;

	UPROPERTY(EditAnywhere, Category = "Rotor Properties")
		float PropellorRotation;

	UPROPERTY(EditAnywhere, Category = "Rotor Properties")
		float RotorTime = .001f;
	UPROPERTY(EditAnywhere, Category = "Rotor Properties")
		bool Break;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void RotateRotor();
	void ApplyBreak();
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);
	void PitchUp();

	void PitchDown();

	void YawRight();

	void YawLeft();

	void RollRight();

	void RollLeft();
};
