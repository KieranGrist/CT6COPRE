// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HelicopterLoadout.generated.h"

UENUM()
enum Loadout
{
	CAS = 0 UMETA(DisplayName = "CAS"),
	AT = 1 UMETA(DisplayName = "AT"),
	MR = 2	UMETA(DisplayName = "MR"),
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class APACHE_SIMULATOR_API UHelicopterLoadout : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UHelicopterLoadout();
	UPROPERTY(EditAnywhere)
		TEnumAsByte<Loadout> HelicopterLoadout;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Slot1;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent *Slot2;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent *Slot3;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent *Slot4;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void CreateSlots();
	void CreatePylons();
	void LoadCAS();
	void LoadAT();
	void LoadMR();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
