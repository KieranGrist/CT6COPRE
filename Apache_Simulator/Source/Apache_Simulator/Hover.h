// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Hover.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APACHE_SIMULATOR_API UHover : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHover();

	UPROPERTY(EditAnywhere, Category = "Hover")
		float Thrust;

	UPROPERTY(EditAnywhere, Category = "Hover")
		float Power;

	UPROPERTY(EditAnywhere, Category = "Hover")
		float Multiplier;

	UPROPERTY(EditAnywhere, Category = "Hover")
		float Height;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
