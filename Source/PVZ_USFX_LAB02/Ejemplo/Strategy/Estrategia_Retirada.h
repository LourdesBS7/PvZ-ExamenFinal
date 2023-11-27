// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EstrategiasZombies.h"
#include "Estrategia_Retirada.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API AEstrategia_Retirada : public AActor, public IEstrategiasZombies
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEstrategia_Retirada();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Defender() override;

	virtual void Atacar() override;


};
