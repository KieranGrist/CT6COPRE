// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ApacheRotor.generated.h"

class AB_Apache;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class APACHE_SIMULATOR_API AApacheRotor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	AApacheRotor();
	UPROPERTY(EditAnywhere)
		AB_Apache* Apache;
	UPROPERTY(EditAnywhere, Category = "Rotor Properties")
		float PropellorRotation;

	UPROPERTY(EditAnywhere, Category = "Rotor Properties")
		float RotorTime = .001f;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Rotor;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void RotateRotor();

	void ApplyBreak();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
