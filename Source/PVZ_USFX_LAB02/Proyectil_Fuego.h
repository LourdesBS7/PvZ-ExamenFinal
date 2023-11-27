// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "Proyectil_Fuego.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API AProyectil_Fuego : public AProyectil
{
	GENERATED_BODY()
public:
	AProyectil_Fuego();
	
	void CambioMesh();
	
	float tiempoCambio;
	bool MeshCambio;

	

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Declarar una función pública para asignar el StaticMesh
	UFUNCTION(BlueprintCallable, Category = "Mesh")
	void AssignMesh(UStaticMesh* NewMesh);
	//UPROPERTY(EditAnywhere)
	//UStaticMeshComponent* MeshBala01;

//protected:
//
//	UPROPERTY(EditAnywhere)
//	UStaticMeshComponent* MeshBala01;
//
//	UPROPERTY(EditAnywhere)
//	UStaticMeshComponent* MeshBala02;
//	UPROPERTY(EditAnywhere)
//	UStaticMeshComponent* MeshBala03;
};
