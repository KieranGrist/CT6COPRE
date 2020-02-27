// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Helicopter Logic/ApacheRotor.h"
#include "AMySpawner.generated.h"
class UApacheRotor;
UCLASS()
class APACHE_SIMULATOR_API AAMySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAMySpawner();
	UPROPERTY(EditAnywhere)
		UApacheRotor *  ApacheRotor;

	UPROPERTY(EditAnywhere)
	int Iteration =5;
	UPROPERTY(EditAnywhere)
		float	TimeToSpawn =1;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
