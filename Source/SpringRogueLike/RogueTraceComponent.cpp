// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueTraceComponent.h"
#include "RogueInterface.h"

// Sets default values for this component's properties
URogueTraceComponent::URogueTraceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void URogueTraceComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	APawn* CompOwner = CastChecked<APawn>(GetOwner());
	FVector EyeLocation;
	FRotator EyeRotation;
	CompOwner->GetActorEyesViewPoint(EyeLocation,EyeRotation);
	FVector End = EyeLocation + (EyeRotation.Vector() * 1000.0f);
	TArray<FHitResult> Hits;
	FCollisionShape CollisionShape;
	CollisionShape.SetSphere(100.0f);
	bool HasHitted = GetWorld()->SweepMultiByObjectType(Hits,EyeLocation,End,FQuat::Identity,ObjectQueryParams,CollisionShape);
	for(auto Hit :Hits)
	{
		AActor*HitActor=Hit.GetActor();
		if(HitActor&&HitActor->Implements<URogueInterface>())
		{
			APawn* MyPawn = CastChecked<APawn>(GetOwner());
			IRogueInterface::Execute_Interact(HitActor,MyPawn);
			break;
		}
	}
	//GetWorld()->LineTraceSingleByObjectType(Hit,EyeLocation,End,ObjectQueryParams);
	//AActor* HitActor = Hit.GetActor();
	// if(HitActor)
	// {
	// 	if(HitActor->Implements<URogueInterface>())
	// 	{
	// 		IRogueInterface::Execute_Interact(HitActor,CompOwner);
	// 	}
	// }
}

void URogueTraceComponent::MultiInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);
	APawn* CompOwner = CastChecked<APawn>(GetOwner());
	FVector EyeLocation;
	FRotator EyeRotation;
	CompOwner->GetActorEyesViewPoint(EyeLocation,EyeRotation);
	FVector End = EyeLocation + (EyeRotation.Vector() * 1000.0f);
	TArray<FHitResult> Hits;
	FCollisionShape CollisionShape;
	CollisionShape.SetSphere(100.0f);
	GetWorld()->SweepMultiByObjectType(Hits,EyeLocation,End,FQuat::Identity,ObjectQueryParams,CollisionShape);
}

// Called when the game starts
void URogueTraceComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URogueTraceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

