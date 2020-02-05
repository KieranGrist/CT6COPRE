// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Helicopter Logic/ApacheEngine.h"
#include "B_Apache.generated.h"

UCLASS()
class APACHE_SIMULATOR_API AB_Apache : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AB_Apache();

	UPROPERTY(EditAnywhere)
		USceneComponent* Apache_AH64;
	UPROPERTY(EditAnywhere)
		AActor* Rotor;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Body;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Tail;

	UPROPERTY(EditAnywhere)
		UApacheEngine* LeftEngine;

	UPROPERTY(EditAnywhere)
		UApacheEngine* RightEngine;
	UPROPERTY(EditAnywhere)
		float LinerDampening;
	UPROPERTY(EditAnywhere)
		float Weight = 5165;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
