// Fill out your copyright notice in the Description page of Project Settings.


#include "Estrategia_Main.h"

#include "Planta_Estrategica.h"
#include "EstrategiaDisparoAdelante.h"
#include "EstrategiaDisparoDiagonal.h"
#include "EstrategiaDisparoRectoDiagonalAA.h"

#include "PVZ_USFX_LAB02/Ejemplo/Observer/ZombieAbanderado.h"
#include "PVZ_USFX_LAB02/Ejemplo/Observer/ZombieAnsioso.h"


// Sets default values
AEstrategia_Main::AEstrategia_Main()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//***********************************
	Ancioso = true;
	Frenetico = true;
	Calmado = true;

}

// Called when the game starts or when spawned
void AEstrategia_Main::BeginPlay()
{
	Super::BeginPlay();
	
	//**************+*************************************************************************


	//Aparicion del zombie abanderado
	ZombieAbanderado = GetWorld()->SpawnActor<AZombieAbanderado>(AZombieAbanderado::StaticClass());
	//Aparicion del primer zombie que es el ansioso y definiendo su zombie como el abanderado
	ZombieAnsioso = GetWorld()->SpawnActor<AZombieAnsioso>(AZombieAnsioso::StaticClass(), FVector(-500.0f, 830.0f, 80.0f), FRotator::ZeroRotator);
	ZombieAnsioso->DefinirZombie(ZombieAbanderado);






	//Spawn the Battle Ship
	APlanta_Estrategica* Planta_Estrategica = GetWorld()->SpawnActor<APlanta_Estrategica>(APlanta_Estrategica::StaticClass(), FVector(-500.0f, -600.0f, 80.0f), FRotator::ZeroRotator);

	//Create the Brute Force Strategy and set it to the Battle Ship
	AEstrategiaDisparoAdelante* EstrategiaDisparoAdelante = GetWorld()->SpawnActor<AEstrategiaDisparoAdelante>(AEstrategiaDisparoAdelante::StaticClass());
	EstrategiaDisparoAdelante->ZombieActual(ZombieAbanderado);


	//Create the Brute Force Strategy and set it to the Battle Ship
	AEstrategiaDisparoDiagonal* EstrategiaDisparoDiagonal = GetWorld()->SpawnActor<AEstrategiaDisparoDiagonal>(AEstrategiaDisparoDiagonal::StaticClass());


	//Create the Brute Force Strategy and set it to the Battle Ship
	AEstrategiaDisparoRectoDiagonalAA* EstrategiaDisparoRectoDiagonalAA = GetWorld()->SpawnActor<AEstrategiaDisparoRectoDiagonalAA>(AEstrategiaDisparoRectoDiagonalAA::StaticClass());

	Planta_Estrategica->CambiarEstrategia(EstrategiaDisparoAdelante);
	//Engage with the current Strategy
	Planta_Estrategica->RealizarEstrategia(Planta_Estrategica);



}


// Called every frame
void AEstrategia_Main::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//****************************************************************
	Super::Tick(DeltaTime);

	if (ZombieAnsioso->energia >= 80 && Calmado)
	{
		ZombieAbanderado->DefinirEstado("Calmado");
		Calmado = false;
	}

	if (ZombieAnsioso->energia >= 40 && ZombieAnsioso->energia <= 79 && Ancioso)
	{
		ZombieAbanderado->DefinirEstado("Enojado");
		Ancioso = false;
	}

	if (ZombieAnsioso->energia <= 39 && Frenetico)
	{
		ZombieAbanderado->DefinirEstado("Frenetico");
		Frenetico = false;
	}


}

