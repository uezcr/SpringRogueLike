// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RogueInterface.h"
#include "RogueInteractActor.generated.h"

class UStaticMeshComponent;
UCLASS()
class SPRINGROGUELIKE_API ARogueInteractActor : public AActor,public IRogueInterface
{
	GENERATED_BODY()

	
public:	
	// Sets default values for this actor's properties
	ARogueInteractActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Interact_Implementation(APawn* InPawn) override;
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", Meta = (AllowPrivateAccess = true))
	UStaticMeshComponent* LidMesh;
};
