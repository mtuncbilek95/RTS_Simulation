// Fill out your copyright notice in the Description page of Project Settings.


#include "TileSpawner.h"

#include "Math/TransformCalculus3D.h"

// Sets default values
ATileSpawner::ATileSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRootComponent"));
	RootComponent = DefaultSceneComponent;
	
	TileBlock = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("InstancedStaticMesh"));
	TileBlock->SetupAttachment(GetRootComponent());

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
	const float centering = 500*(Row-1); //I'm using this to centered the whole tilemap.
	FVector TileLocation = FVector(-centering, -centering, 20);
	//column x row matrix spawner
	for(int i=0; i<Row; i++)
	{
		for(int j=0; j<Row; j++)
		{
			FTransform TileTransform = FTransform(TileLocation);
			TileBlock->AddInstance(TileTransform);
			TileLocation += FVector(1000,0,0);
		}
		TileLocation += FVector(-Row*1000,1000,0);
		
	}
	
	/* ---------MORE ADVANCED APPROACH---------
	Let say we have single unit length and total length for tiles.

	Each tile's length
	float singleTile = 500;
	
	Total tile's length
	float totalTile= 5000;

	int Row = totalTile/singleTile;
	
	float newScaleValue = singleTile/1000;

	scaled Tiles
	FScale TileScale = FScale(newScaleValue, newScaleValue, 1);

	we can update centering value as
	const float centering = (singleTile/2)*(Row-1);
	
	new transform data
	FTransform TileTransform = FTransform(TileLocation, Scale);

	Those implementations work just fine. 
	 */
}


