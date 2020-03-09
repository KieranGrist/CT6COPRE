// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FlightPhysics.generated.h"

class AB_Apache;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APACHE_SIMULATOR_API UFlightPhysics : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFlightPhysics();
	UPROPERTY(EditAnywhere)
		AB_Apache* Apache;
	UPROPERTY(EditAnywhere)
		FVector Velocity;
	UPROPERTY(EditAnywhere)
	FVector Location;

	UPROPERTY(EditAnywhere)
		FVector Wind;
	UPROPERTY(EditAnywhere)
	FVector Gravity;

		
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	float Delta;
		float GetDelta();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	void AddForce(FVector Force);

};
