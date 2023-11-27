// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estrategias.h"
#include "EstrategiaDisparoAtras.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API AEstrategiaDisparoAtras : public AActor, public IEstrategias
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaDisparoAtras();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//Execute the Maneuver of this Strategy
	virtual void EstrategiaPlanta(AActor* PlantaHabi) override;
};
