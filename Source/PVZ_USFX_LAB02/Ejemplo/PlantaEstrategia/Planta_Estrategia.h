// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PVZ_USFX_LAB02/Planta_Ataque.h"
#include "Estrategias.h"
#include "Planta_Estrategia.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API APlanta_Estrategia : public APlanta_Ataque
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlanta_Estrategia();

	APlanta_Estrategia* plantaAtak;

	

private:

	//The current Battle Strategy
	IEstrategias* Estrategias;
	class AEstrategiaDisparoLento* DisparoLento;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Change the Maneuver and set "BattleStrategy" variable
	void CambiarEstrategia(AActor* PlantaEstrategia);
	// Engage with the current Battle Strategy
	void RealizarEstrategia(AActor* PlantaHabi);

	void GetTiempoTranscurrido(float _TiempoTranscurrido);
	void SetDispararAtras(bool _DispararAtras);
	void CambioMeshProyectil();


};
