// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaDisparoRapido.h"
#include "Planta_Estrategia.h"

// Sets default values
AEstrategiaDisparoRapido::AEstrategiaDisparoRapido()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaDisparoRapido::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaDisparoRapido::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaDisparoRapido::EstrategiaPlanta(AActor* PlantaHabi)
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow,TEXT("Estrategia de disparo rapido"));
	APlanta_Estrategia* PlantaEs = Cast<APlanta_Estrategia>(PlantaHabi);
	PlantaEs->GetTiempoTranscurrido(0.2f);
	
}

