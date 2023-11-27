// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Estrategias.h"
#include "EstrategiaDisparoLento.generated.h"

UCLASS()
class PVZ_USFX_LAB02_API AEstrategiaDisparoLento : public AActor, public IEstrategias
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstrategiaDisparoLento();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Execute the Maneuver of this Strategy
	virtual void EstrategiaPlanta(AActor* PlantaHabi) override;

	void castProyectil(AActor* other);

	class AProyectil_Fuego* Proyectil;


	void FireShot(FVector FireDirection);
	class AProyectil_Fuego* Proyectil_Fuego;

	float TiempoTranscurrido;
	float CurrentTiempoTranscurrido;

	//Si tiene permitido disparar
	uint32 bCanFire : 1;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FVector GunOffset;

	FVector Location;

	TArray<UStaticMesh*> contMesh;

	void ZombieActual(AActor* other);

	class AZombieAbanderado* ZombieAbanderado;
};
