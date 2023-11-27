// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil_Fuego.h"
//#include "ConstructorHelpers.h"
#include "Engine/StaticMesh.h"


AProyectil_Fuego::AProyectil_Fuego()
{

	static ConstructorHelpers::FObjectFinder<UStaticMesh> FuegoMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));

	MeshBala->SetStaticMesh(FuegoMesh.Object);

	tiempoCambio = 0.5f;
	MeshCambio = true;
}

void AProyectil_Fuego::CambioMesh()
{
	
	UStaticMesh* NuevoMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	AssignMesh(NuevoMesh);

	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Se cambio el mesh"));
}

void AProyectil_Fuego::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//tiempoCambio -= DeltaTime;
	//if (tiempoCambio <= 0 && MeshCambio)
	//{
	//	CambioMesh();
	//	MeshCambio = false;
	//}
	

}

void AProyectil_Fuego::AssignMesh(UStaticMesh* NewMesh)
{
	// Asegúrate de que el componente no sea nulo
	if (MeshBala)
	{
		// Establece el nuevo StaticMesh en el componente de StaticMesh
		MeshBala->SetStaticMesh(NewMesh);
	}
	else
	{
		// Manejo de error si el componente de StaticMesh es nulo
		UE_LOG(LogTemp, Error, TEXT("El componente de StaticMesh es nulo."));
	}
}
