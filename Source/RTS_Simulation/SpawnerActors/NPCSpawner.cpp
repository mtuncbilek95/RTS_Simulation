// Fill out your copyright notice in the Description page of Project Settings.


#include "NPCSpawner.h"

#include "NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "RTS_Simulation/AI/LocationInterface.h"

// Sets default values
ANPCSpawner::ANPCSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPCSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnActors();
}

// Called every frame
void ANPCSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//Spawns actors according to FormationLocations that is saved in Array.
void ANPCSpawner::SpawnActors()
{
	for(int i=0; i<10; i++)
	{
		const FVector Location = GetActorLocation() + FormationVector[i];
		NPC_Array.Add(UAIBlueprintHelperLibrary::SpawnAIFromClass(GetWorld(), AIPawn, UBT, Location));
	}
}

/*
void ANPCSpawner::MoveInGroup()
{
	for (const AActor* NPC:NPC_Array)
	{
		ILocationInterface* Interface = Cast<ILocationInterface>(NPC->GetRootComponent());
		if(Interface)
		{
			bugTester = true;
			Interface->Set_Location(NPC->GetActorLocation() + TargetLocation);
		}
	}
}
*/
void ANPCSpawner::LocationPrint_Implementation()
{
	ILocationSpawnerInterface::LocationPrint_Implementation();
}

void ANPCSpawner::MoveInGroup_Implementation()
{
	ILocationSpawnerInterface::MoveInGroup_Implementation();
}



