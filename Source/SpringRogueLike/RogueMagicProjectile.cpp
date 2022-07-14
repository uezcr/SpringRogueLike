// Fill out your copyright notice in the Description page of Project Settings.


#include "RogueMagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ARogueMagicProjectile::ARogueMagicProjectile(const FObjectInitializer& ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SetRootComponent(SphereComponent);
	SphereComponent->SetCollisionProfileName("Particle");
	EffectComponent = CreateDefaultSubobject<UParticleSystemComponent>("EffectSystem");
	EffectComponent->SetupAttachment(SphereComponent);
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
	MovementComponent->InitialSpeed = 1000.0f;
	MovementComponent->bRotationFollowsVelocity = true;
	MovementComponent->bInitialVelocityInLocalSpace = true;
}

// Called when the game starts or when spawned
void ARogueMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARogueMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

