// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "B_Switch.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APACHE_SIMULATOR_API UB_Switch : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UB_Switch();
	UPROPERTY(EditAnywhere)
		bool IsOn;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void ActionWhenOn();
	virtual void ActionWhenOff();
		
};
