// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LocationSpawnerInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULocationSpawnerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RTS_SIMULATION_API ILocationSpawnerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void LocationPrint();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void MoveInGroup();
};
