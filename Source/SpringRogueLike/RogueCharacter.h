// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RogueCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class URogueTraceComponent;
class UAnimMontage;

UCLASS()
class SPRINGROGUELIKE_API ARogueCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARogueCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Delta);
	void MoveRight(float Delta);
	void Turn(float Delta);
	void LookUp(float Delta);
	void PrimaryAttack();
	void PrimaryInteract();
	void PrimaryAttack_TimeElapsed();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle")
	TSubclassOf<AActor> ParticleClass;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Animations")
	UAnimMontage* AttackMontage;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|Camera", Meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|Camera", Meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components|Custom", Meta = (AllowPrivateAccess = "true"))
	URogueTraceComponent* TraceComponent;
	FTimerHandle TimerHandle_PrimaryAttack;
};
