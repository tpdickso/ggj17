// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Math/Vector.h"
#include "GameFramework/Actor.h"
#include "FluidSimCells.generated.h"

UCLASS()
class ROLLAROUND_API AFluidSimCells : public AActor
{
	GENERATED_BODY()

	FVector *CellVelocities;

	void GenerateParticlesAndGrid();
	
public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 GridSizeX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 GridSizeY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 GridSizeZ;

	// Sets default values for this actor's properties
	AFluidSimCells();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
