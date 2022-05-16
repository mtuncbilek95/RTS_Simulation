// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LocationInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class ULocationInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RTS_SIMULATION_API ILocationInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Set_LocationPure(FVector Location) = 0;
	
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category= "Location")
	void Set_Location(FVector Location);
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category= "Location")
	void Get_Location(FVector &Location);

	UFUNCTION()
	virtual void Get_LocationPure(FVector &Location) = 0;
};
