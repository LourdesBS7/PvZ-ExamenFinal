// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiasZombies.h"
#include "Zombie_Estrategico.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API AZombie_Estrategico : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AZombie_Estrategico();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//The current Battle Strategy
	IEstrategiasZombies* Estrategias;

public:

	// Change the Maneuver and set "BattleStrategy" variable
	void AlterarEstrategia(AActor* myZombieEstrategia);

	// Engage with the current Battle Strategy
	void Realizar();


};