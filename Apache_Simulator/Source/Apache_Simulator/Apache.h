// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Apache.generated.h"

UCLASS()
class APACHE_SIMULATOR_API AApache : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AApache();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ApacheModel;
};
