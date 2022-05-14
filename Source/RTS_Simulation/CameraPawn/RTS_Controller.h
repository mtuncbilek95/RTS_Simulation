// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "RTS_Controller.generated.h"

/**
 * 
 */
UCLASS()
class RTS_SIMULATION_API ARTS_Controller : public APlayerController
{
	GENERATED_BODY()
public:
	
	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value) const;
	
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value) const;

	UFUNCTION(BlueprintCallable)
	void Zoom(float Value) const;
	
	UPROPERTY(EditAnywhere)
	float MovementSpeed;

	
};
