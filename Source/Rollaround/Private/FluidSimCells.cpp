// Fill out your copyright notice in the Description page of Project Settings.

#include "Rollaround.h"
#include "FluidSimCells.h"

// Sets default values
AFluidSimCells::AFluidSimCells()
	: GridSizeX(8)
	, GridSizeY(8)
	, GridSizeZ(8)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GenerateParticlesAndGrid();

}

// Called when the game starts or when spawned
void AFluidSimCells::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFluidSimCells::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	for (int32 z = 0; z < GridSizeZ; ++z)
	for (int32 y = 0; y < GridSizeY; ++y)
	for (int32 x = 0; x < GridSizeX; ++x)
	{
		int32 index = x + (y + z * GridSizeY) * GridSizeX;
		ParticleVelocities[index].Z -= DeltaTime * 9.81;
	}
}

void AFluidSimCells::PostEditChangeProperty(FPropertyChangedEvent &PropertyChangedEvent)
{
	GenerateParticlesAndGrid();
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void AFluidSimCells::GenerateParticlesAndGrid()
{
	if (ParticleVelocities) delete[] ParticleVelocities;
	ParticleVelocities = new FVector[GridSizeX * GridSizeY * GridSizeZ];
}

