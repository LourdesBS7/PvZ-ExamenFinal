// Fill out your copyright notice in the Description page of Project Settings.


#include "EstrategiaDisparoAdelante.h"

#include "Planta_Estrategica.h"
#include "PVZ_USFX_LAB02/Proyectil_Fuego.h"
#include "PVZ_USFX_LAB02/Ejemplo/Observer/ZombieAbanderado.h"


// Sets default values
AEstrategiaDisparoAdelante::AEstrategiaDisparoAdelante()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//***********************************
	bCanFire = true;

	TiempoTranscurrido = 1.0f;
	CurrentTiempoTranscurrido = 1.5f;
	GunOffset = FVector(0.f, 40.f, 10.f);


}

// Called when the game starts or when spawned
void AEstrategiaDisparoAdelante::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AEstrategiaDisparoAdelante::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//***********************************
	TiempoTranscurrido -= DeltaTime;

	if (TiempoTranscurrido <= 0.0f) {

		FireShot(FVector(0.0f, 1.0f, 0.0f));
		TiempoTranscurrido = 1.5f;
	}

}



//**************************************************************

void AEstrategiaDisparoAdelante::DispararBala(AActor* PlantaHabi)
{
	//Execute the routine of this type of Strategy
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, TEXT("Estrategia de disparo Adelante"));
	APlanta_Estrategica* PlantaEs = Cast<APlanta_Estrategica>(PlantaHabi);
	PlantaEs->GetTiempoTranscurrido(3.0f);

	Location = PlantaEs->GetActorLocation();

	UStaticMesh* NuevoMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	contMesh.Add(NuevoMesh);
	NuevoMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	contMesh.Add(NuevoMesh);
	NuevoMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	contMesh.Add(NuevoMesh);
	NuevoMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));
	contMesh.Add(NuevoMesh);
	NuevoMesh = LoadObject<UStaticMesh>(nullptr, TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_180.Shape_Pipe_180'"));
	contMesh.Add(NuevoMesh);




}

void AEstrategiaDisparoAdelante::castProyectil(AActor* other)
{

}

void AEstrategiaDisparoAdelante::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = Location + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				Proyectil_Fuego = World->SpawnActor<AProyectil_Fuego>(SpawnLocation, FireRotation);

				int NumMesh = FMath::RandRange(0, 4);
				FString Estado = ZombieAbanderado->GetEstado();
				if (!Estado.Compare("Enojado"))
				{
					Proyectil_Fuego->AssignMesh(contMesh[2]);

				}
				if (!Estado.Compare("Frenetico"))
				{
					Proyectil_Fuego->AssignMesh(contMesh[3]);
				}
				if (!Estado.Compare("Calmado"))
				{
					Proyectil_Fuego->AssignMesh(contMesh[4]);
				}

			}

			//bCanFire = false;
			//World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &APlanta_Ataque::ShotTimerExpired, FireRate);

		}
	}
}


void AEstrategiaDisparoAdelante::ZombieActual(AActor* other)
{
	ZombieAbanderado = Cast<AZombieAbanderado>(other);
}
