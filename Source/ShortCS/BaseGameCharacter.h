// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseGameCharacter.generated.h"

UCLASS()
class SHORTCS_API ABaseGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseGameCharacter();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintImplementablEevent, Category = "BaseGameCharacter")
		void DamageBaseGameCharacter(float Amount);

};
