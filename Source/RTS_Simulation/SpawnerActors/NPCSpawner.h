// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "RTS_Simulation/AI/LocationSpawnerInterface.h"
#include "NPCSpawner.generated.h"

UCLASS()
class RTS_SIMULATION_API ANPCSpawner : public AActor, public ILocationSpawnerInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANPCSpawner();

	FTimerHandle TimerHandle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int32 CallTracker = 3;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnActors();

	UPROPERTY(EditAnywhere)
	TSubclassOf<APawn> AIPawn;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* UBT;

	UPROPERTY(EditAnywhere)
	TArray<FVector> FormationVector;

	UPROPERTY(BlueprintReadWrite)
	TArray<AActor*> NPC_Array;

	UPROPERTY(BlueprintReadWrite)
	FVector TargetLocation;
	
	void LocationPrint_Implementation() override;

	void MoveInGroup_Implementation() override;

	UPROPERTY(BlueprintReadWrite)
	bool bugTester;
};
