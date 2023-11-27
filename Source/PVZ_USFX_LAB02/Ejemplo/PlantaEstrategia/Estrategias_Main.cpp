// Fill out your copyright notice in the Description page of Project Settings.


#include "Estrategias_Main.h"
#include "Planta_Estrategia.h"
#include "EstrategiaDisparoRapido.h"
#include "EstrategiaDisparoLento.h"
#include "EstrategiaDisparoAtras.h"

#include "PVZ_USFX_LAB02/Ejemplo/Observer/ZombieAbanderado.h"
#include "PVZ_USFX_LAB02/Ejemplo/Observer/ZombieAnsioso.h"

// Sets default values
AEstrategias_Main::AEstrategias_Main()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Ancioso = true;
	Frenetico = true;
	Calmado = true;
}

// Called when the game starts or when spawned
void AEstrategias_Main::BeginPlay()
{
	Super::BeginPlay();




	//Aparicion del zombie abanderado
	ZombieAbanderado = GetWorld()->SpawnActor<AZombieAbanderado>(AZombieAbanderado::StaticClass());
	//Aparicion del primer zombie que es el ansioso y definiendo su zombie como el abanderado
	ZombieAnsioso = GetWorld()->SpawnActor<AZombieAnsioso>(AZombieAnsioso::StaticClass(),  FVector(-500.0f, 830.0f, 80.0f), FRotator::ZeroRotator);
	ZombieAnsioso->DefinirZombie(ZombieAbanderado);
	





	//Spawn the Battle Ship
	APlanta_Estrategia* Planta_Estrategia = GetWorld()->SpawnActor<APlanta_Estrategia>(APlanta_Estrategia::StaticClass(), FVector(-500.0f, -600.0f, 80.0f), FRotator::ZeroRotator);

	//Create the Brute Force Strategy and set it to the Battle Ship
	AEstrategiaDisparoRapido* EstrategiaDisparoRapido = GetWorld()->SpawnActor<AEstrategiaDisparoRapido>(AEstrategiaDisparoRapido::StaticClass());

	//Create the Brute Force Strategy and set it to the Battle Ship
	AEstrategiaDisparoLento* EstrategiaDisparoLento = GetWorld()->SpawnActor<AEstrategiaDisparoLento>(AEstrategiaDisparoLento::StaticClass());
	EstrategiaDisparoLento->ZombieActual(ZombieAbanderado);
	//Create the Brute Force Strategy and set it to the Battle Ship
	AEstrategiaDisparoAtras* EstrategiaDisparoAtras = GetWorld()->SpawnActor<AEstrategiaDisparoAtras>(AEstrategiaDisparoAtras::StaticClass());

	Planta_Estrategia->CambiarEstrategia(EstrategiaDisparoLento);
	//Engage with the current Strategy
	Planta_Estrategia->RealizarEstrategia(Planta_Estrategia);



}

// Called every frame
void AEstrategias_Main::Tick(float DeltaTime)
{
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

