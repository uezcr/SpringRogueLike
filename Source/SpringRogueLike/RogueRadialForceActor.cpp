// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueRadialForceActor.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"


// Sets default values
ARogueRadialForceActor::ARogueRadialForceActor(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnMeshComponentBeginHit);
	this->SetRootComponent(MeshComponent);
	RadialForceComponent = CreateDefaultSubobject<URadialForceComponent>("RadialForceComponent");
}

// Called when the game starts or when spawned
void ARogueRadialForceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARogueRadialForceActor::OnMeshComponentBeginHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadialForceComponent->FireImpulse();
}

// Called every frame
void ARogueRadialForceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

