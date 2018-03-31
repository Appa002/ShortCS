// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Camera/CameraComponent.h"
#include "BaseGameCharacter.h"

#include "BaseGun.generated.h"

UCLASS()
class SHORTCS_API ABaseGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGun();

	UPROPERTY(EditAnyWhere, Category = "BaseGun")
		float GunPerShootDamage;

	USkeletalMeshComponent* SkeletalMesh;
	USceneComponent* FireMarkerContainer;
	USceneComponent* FireMarker;
	UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Base Gun")
		void  FireGun();

	UFUNCTION(BlueprintCallable, Category = "Base Gun")
		void  SetCamera(UCameraComponent* NewCamera);


};
