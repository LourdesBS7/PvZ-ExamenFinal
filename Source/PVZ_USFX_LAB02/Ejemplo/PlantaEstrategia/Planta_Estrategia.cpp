// Fill out your copyright notice in the Description page of Project Settings.


#include "Planta_Estrategia.h"
#include <Kismet/GameplayStatics.h>
#include "PVZ_USFX_LAB02/Zombie.h"
#include "EstrategiaDisparoLento.h"

// Sets default values
APlanta_Estrategia::APlanta_Estrategia()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}



// Called when the game starts or when spawned
void APlanta_Estrategia::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlanta_Estrategia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (false)
	{
		TiempoTranscurrido -= DeltaTime;
		if (TiempoTranscurrido <= 0.0f) {

			AtaquePlanta();
			TiempoTranscurrido = CurrentTiempoTranscurrido;
		}
	}
}

void APlanta_Estrategia::CambiarEstrategia(AActor* PlantaEstrategia)
{
	//Try to cast the passed Strategy and set it to the current one
	Estrategias = Cast<IEstrategias>(PlantaEstrategia);

}

void APlanta_Estrategia::RealizarEstrategia(AActor* PlantaHabi)
{
	Estrategias->EstrategiaPlanta(PlantaHabi);
	
}

void APlanta_Estrategia::GetTiempoTranscurrido(float _TiempoTranscurrido)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Entro a Get FireRate"));
	TiempoTranscurrido = 0.0f;
	CurrentTiempoTranscurrido = _TiempoTranscurrido;
	

    
}

void APlanta_Estrategia::SetDispararAtras(bool _DispararAtras)
{
	DispararAtras = _DispararAtras;
}

void APlanta_Estrategia::CambioMeshProyectil()
{
	UStaticMesh* NuevoMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	//AssignMesh(NuevoMesh);
	//Proyectil_Fuego->AssignMesh(NuevoMesh);
}





