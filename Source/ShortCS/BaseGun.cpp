// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseGun.h"


// Sets default values
ABaseGun::ABaseGun()
{
	Camera = nullptr;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("SkeletalMesh"));
	RootComponent = SkeletalMesh;

	FireMarkerContainer = CreateDefaultSubobject<USceneComponent>(FName("FireMarkerContainer"));


	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, false);
	FireMarkerContainer->AttachToComponent(RootComponent, rules);
}

// Called when the game starts or when spawned
void ABaseGun::BeginPlay()
{
	Super::BeginPlay();
	FireMarker = FireMarkerContainer->GetChildComponent(0);
}

// Called every frame
void ABaseGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseGun::FireGun()
{
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("GunShoot")), false, this);
	RV_TraceParams.bTraceAsyncScene = true;
	RV_TraceParams.bReturnPhysicalMaterial = false;

	//Re-initialize hit info
	FHitResult RV_Hit(ForceInit);

	FVector Start = Camera->GetComponentLocation();
	FVector End = Camera->GetComponentLocation() + Camera->GetForwardVector() * 1000;

	//call GetWorld() from within an actor extending class
	bool IsHit = GetWorld()->LineTraceSingleByChannel(
		RV_Hit,
		Start,
		End,
		ECC_Visibility,
		RV_TraceParams
	);

	if (IsHit) 
	{
		FString ActorName = RV_Hit.Actor->GetName();
		if (RV_Hit.Actor->ActorHasTag("Player")) {
			ABaseGameCharacter* HitActorAsBaseGameCharacter = Cast<ABaseGameCharacter>(RV_Hit.Actor);
			HitActorAsBaseGameCharacter->DamageBaseGameCharacter(PerShootBaseDamage);
		}

		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, ActorName, true);
	}
}

void ABaseGun::SetCamera(UCameraComponent * NewCamera)
{
	Camera = NewCamera;
}


