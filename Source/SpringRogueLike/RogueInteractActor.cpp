// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueInteractActor.h"

// Sets default values
ARogueInteractActor::ARogueInteractActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

