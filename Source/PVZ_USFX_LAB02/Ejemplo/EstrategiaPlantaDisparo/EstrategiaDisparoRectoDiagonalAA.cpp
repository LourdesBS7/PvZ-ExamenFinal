// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaDisparoRectoDiagonalAA.h"
#include "Planta_Estrategica.h"

// Sets default values
AEstrategiaDisparoRectoDiagonalAA::AEstrategiaDisparoRectoDiagonalAA()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaDisparoRectoDiagonalAA::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaDisparoRectoDiagonalAA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaDisparoRectoDiagonalAA::DispararBala(AActor* PlantaHabi)
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Estrategia de Disparo Recto y Diagonal hacia Adelante y atras"));   //no utilizar comas ni acentos
	APlanta_Estrategica* PlantaEs = Cast<APlanta_Estrategica>(PlantaHabi);
	PlantaEs->SetDispararAtras(true);

}

