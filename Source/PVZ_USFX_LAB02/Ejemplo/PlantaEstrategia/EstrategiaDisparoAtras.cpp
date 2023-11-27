// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaDisparoAtras.h"
#include "Planta_Estrategia.h"

// Sets default values
AEstrategiaDisparoAtras::AEstrategiaDisparoAtras()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaDisparoAtras::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaDisparoAtras::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstrategiaDisparoAtras::EstrategiaPlanta(AActor* PlantaHabi)
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Estrategia de disparo Atras"));
	APlanta_Estrategia* PlantaEs = Cast<APlanta_Estrategia>(PlantaHabi);
	PlantaEs->SetDispararAtras(true);
}

