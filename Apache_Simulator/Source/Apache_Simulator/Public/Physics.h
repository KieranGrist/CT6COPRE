// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Physics.generated.h"

UCLASS()
class APACHE_SIMULATOR_API APhysics : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APhysics();

	UPROPERTY(EditAnywhere)
		USceneComponent* SceneCube;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Cube;
	UPrimitiveComponent* PhysicsRef;
	UPROPERTY(EditAnywhere)
		float Collective;
	UPROPERTY(EditAnywhere)
		float Power;
	UPROPERTY(EditAnywhere)
		float Thrust = 0;
	UPROPERTY(EditAnywhere)
		float PowerToApply = 0;
	UPROPERTY(EditAnywhere)
		float Speed;
	UPROPERTY(EditAnywhere)
		float Multiplier = 0;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
