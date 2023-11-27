// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaDisparoDiagonal.h"
#include "Planta_Estrategica.h"

// Sets default values
AEstrategiaDisparoDiagonal::AEstrategiaDisparoDiagonal()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstrategiaDisparoDiagonal::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstrategiaDisparoDiagonal::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

void AEstrategiaDisparoDiagonal::DispararBala(AActor* PlantaHabi)
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Estrategia de disparo Diagonal"));
	APlanta_Estrategica* PlantaEs = Cast<APlanta_Estrategica>(PlantaHabi);
	PlantaEs->GetTiempoTranscurrido(0.2f);




}

