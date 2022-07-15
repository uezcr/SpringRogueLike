// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueInteractActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARogueInteractActor::ARogueInteractActor(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	this->SetRootComponent(BaseMesh);
	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>("LidMesh");
	LidMesh->SetupAttachment(BaseMesh);
}

// Called when the game starts or when spawned
void ARogueInteractActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARogueInteractActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARogueInteractActor::Interact_Implementation(APawn* InPawn)
{
	LidMesh->SetRelativeLocation(FVector(0.0f,0.0f,100.0f));
}

