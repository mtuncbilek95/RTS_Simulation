// Fill out your copyright notice in the Description page of Project Settings.


#include "TileSpawner.h"

// Sets default values
ATileSpawner::ATileSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATileSpawner::BeginPlay()
{
	Super::BeginPlay();
	TileSpawn();
}

// Called every frame
void ATileSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATileSpawner::TileSpawn()
{
	FVector TileLocation = FVector(0, 0, 20);
	//column x row matrix spawner
	for(int i=0; i<Row; i++)
	{
		for(int j=0; j<Row; j++)
		{
			GetWorld()->SpawnActor<AActor>(ActorToSpawn, TileLocation, FRotator(0,0,0));
			TileLocation += FVector(0,1000,0);
		}
		TileLocation += FVector(1000,-Row*1000,0);
	}
}


