// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LocationInterface.h"
#include "GameFramework/Character.h"
#include "NPC_Character.generated.h"

UCLASS()
class RTS_SIMULATION_API ANPC_Character : public ACharacter, public ILocationInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC_Character();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector TargetLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Set_LocationPure(FVector Location) override;

	virtual void Get_LocationPure(FVector &Location) override;

	void Get_Location_Implementation(FVector& Location) override;

	void Set_Location_Implementation(FVector Location) override;
};
