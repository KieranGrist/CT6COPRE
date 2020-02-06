// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "ApacheCollective.generated.h"

class AB_Apache;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APACHE_SIMULATOR_API UApacheCollective : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UApacheCollective();
	UPROPERTY(EditAnywhere)
		float Collective;
	UPROPERTY(EditAnywhere)
		float Power;
	UPROPERTY(EditAnywhere)
		AB_Apache* Apache;

	UPROPERTY(EditAnywhere)
		float Thrust = 0;
	UPROPERTY(EditAnywhere)
		float PowerToApply = 0;
	UPROPERTY(EditAnywhere)
		float Multiplier = 51318.222656;

	UPrimitiveComponent* PhysicsRef;

	UPROPERTY(EditAnywhere)
		float Stage1;
	UPROPERTY(EditAnywhere)
		float	Stage2;
	UPROPERTY(EditAnywhere)
		float Stage3;
	UPROPERTY(EditAnywhere)
		float 	Stage4;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
