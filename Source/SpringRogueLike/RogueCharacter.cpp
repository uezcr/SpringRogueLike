// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueCharacter.h"

#include "RogueTraceComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "RogueTraceComponent.h"

// Sets default values
ARogueCharacter::ARogueCharacter(const FObjectInitializer& ObjectInitializer)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	TraceComponent = CreateDefaultSubobject<URogueTraceComponent>("TraceComponent");

	CameraBoom->SetupAttachment(RootComponent);
	FollowCamera->SetupAttachment(CameraBoom);

	this->bUseControllerRotationYaw = false;
	CameraBoom->bUsePawnControlRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;

}

// Called when the game starts or when spawned
void ARogueCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARogueCharacter::MoveForward(float Delta)
{
	if (Controller != nullptr && Delta != 0)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Delta);
	}
}

void ARogueCharacter::MoveRight(float Delta)
{
	if (Controller != nullptr && Delta != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, Delta);
	}
}

void ARogueCharacter::Turn(float Delta)
{
	AddControllerYawInput(Delta);
}

void ARogueCharacter::LookUp(float Delta)
{
	AddControllerPitchInput(Delta);
}

void ARogueCharacter::PrimaryAttack()
{
	PlayAnimMontage(AttackMontage);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_PrimaryAttack,this,&ThisClass::PrimaryAttack_TimeElapsed,0.2f);
	//GetWorld()->GetTimerManager().ClearTimer(TimerHandle_PrimaryAttack);
}

void ARogueCharacter::PrimaryInteract()
{
	TraceComponent->PrimaryInteract();
}

void ARogueCharacter::PrimaryAttack_TimeElapsed()
{
	FVector SpawnLocation = GetMesh()->GetSocketLocation("Muzzle_01");
	FTransform SpawnTransform(GetControlRotation(), SpawnLocation);
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	SpawnParameters.Instigator=this;
	GetWorld()->SpawnActor<AActor>(ParticleClass,SpawnTransform,SpawnParameters);
}

// Called every frame
void ARogueCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARogueCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ThisClass::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ThisClass::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ThisClass::PrimaryAttack);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("PrimaryInteract",IE_Pressed,this,&ThisClass::PrimaryInteract);
}

