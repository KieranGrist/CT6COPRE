// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ApacheEngine.generated.h"


UCLASS(Blueprintable,ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APACHE_SIMULATOR_API UApacheEngine : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UApacheEngine();
	UPROPERTY(VisibleAnywhere)
		bool IsOn = false;
	UPROPERTY(EditAnywhere)
	float Power = 0.0f;
	UPROPERTY(EditAnywhere)
	float Damage;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void EngineOn();

	void EngineOff();

		
};
