// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "User_charachter.generated.h"

UCLASS()
class FIRSTPERSONSHOOTER_API AUser_charachter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AUser_charachter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AGUN_NPC> FP_gun_BP;

	UFUNCTION(BlueprintCallable,Category="Shooting")
	void Call_fire();

private:
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	AGUN_NPC* gun;

};
