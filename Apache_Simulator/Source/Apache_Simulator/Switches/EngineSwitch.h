// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Switches/B_Switch.h"
#include "Helicopter Logic/ApacheEngine.h"
#include "Components/ActorComponent.h"
#include "EngineSwitch.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APACHE_SIMULATOR_API UEngineSwitch : public UB_Switch
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEngineSwitch();
	UPROPERTY(EditAnywhere)
	UApacheEngine* ApacheEngine;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void  ActionWhenOn() override;
	virtual void  ActionWhenOff() override;
		
};
