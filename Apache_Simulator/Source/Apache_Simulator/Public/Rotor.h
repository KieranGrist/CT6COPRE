// Fill out your copyright notice in the Description page of Project Settings.
             
#pragma once

#include "CoreMinimal.h"
#include "Helicopter Logic/ApacheRotor.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "Rotor.generated.h"

UCLASS()
class APACHE_SIMULATOR_API ARotor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ARotor();
	UPROPERTY(EditAnywhere)
	USceneComponent* RotorSceneComponent;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* RotorMesh;

	UPROPERTY(EditAnywhere)
		UApacheRotor* ApacheRotor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)  override;

};
