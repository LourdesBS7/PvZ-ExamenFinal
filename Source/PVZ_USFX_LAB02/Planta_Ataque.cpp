// Fill out your copyright notice in the Description page of Project Settings.


#include "Planta_Ataque.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

#include "Proyectil.h"
#include "Proyectil_Fuego.h"

#include "TimerManager.h"
#include <cmath>

APlanta_Ataque::APlanta_Ataque()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



	static ConstructorHelpers::FObjectFinder<UStaticMesh> PlantAtaqueMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));

	MeshPlanta->SetStaticMesh(PlantAtaqueMesh.Object);

	MeshPlanta->SetRelativeScale3D(FVector(0.5f, 0.5f, 1.5f));



	bCanFire = true;

	GunOffset = FVector(40.f, 40.f, 10.f);

	FireRate = 0.5f;

	energia = 200;

	CantidadDisparos = 1;
	contador = 1;

	TiempoTranscurrido = 0.5f;
	CurrentTiempoTranscurrido = 0.5f;
	DispararAtras = false;
	//Ocultar el actor sin destruirlo
	//SetActorHiddenInGame(true);

}


void APlanta_Ataque::BeginPlay()
{
	Super::BeginPlay();


	//UWorld* const World = GetWorld();

	//GetWorldTimerManager().SetTimer(ManejoTiempo, this, &APlanta_Ataque::AtaquePlanta, FireRate, true, 0.1f);

}

void APlanta_Ataque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//CurrentTiempoTranscurrido = TiempoTranscurrido;
	//TiempoTranscurrido -= DeltaTime;
	//

	//if (TiempoTranscurrido <= 0.0f) {

	//	AtaquePlanta();
	//	TiempoTranscurrido = 0.5f;
	//}

}



void APlanta_Ataque::AtaquePlanta()
{
	//UStaticMesh* NuevoMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	FireShot(FVector(0.0f, 1.0f, 0.0f));
	//Proyectil_Fuego->AssignMesh(NuevoMesh);
	if (DispararAtras)
	{
		FireShot(FVector(0.0f, -1.0f, 0.0f));
	}

}


void APlanta_Ataque::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				Proyectil_Fuego = World->SpawnActor<AProyectil_Fuego>(SpawnLocation, FireRotation);

				//UStaticMesh* NuevoMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
				//AssignMesh(NuevoMesh);
				//Proyectil_Fuego->AssignMesh(NuevoMesh);
			}

			//bCanFire = false;
			//World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &APlanta_Ataque::ShotTimerExpired, FireRate);

		}
	}
}

AProyectil_Fuego* APlanta_Ataque::GetProyectile()
{
	
	return Proyectil_Fuego;
}




