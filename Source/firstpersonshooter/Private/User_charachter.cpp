// Fill out your copyright notice in the Description page of Project Settings.


#include "User_charachter.h"
#include "Camera/CameraComponent.h"
#include"GUN_NPC.h"
#include "Animation/AnimInstance.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AUser_charachter::AUser_charachter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*FP Camera Setup*/
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	/*FP mesh*/
	FP_mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	FP_mesh->SetOnlyOwnerSee(true);
	FP_mesh->SetupAttachment(FirstPersonCameraComponent);
	FP_mesh->bCastDynamicShadow = false;
	FP_mesh->CastShadow = false;
	FP_mesh->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	FP_mesh->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

}

// Called when the game starts or when spawned
void AUser_charachter::BeginPlay()
{
	Super::BeginPlay();

	if (FP_gun_BP == NULL)
	{
		UE_LOG(LogTemp, Warning, TEXT("No gun bluperint attached"));
		return;
	}

	else
	{
		gun = GetWorld()->SpawnActor<AGUN_NPC>(FP_gun_BP);
		gun->AttachToComponent(FP_mesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
		gun->AnimInstance = FP_mesh->GetAnimInstance();
	}
	
}

// Called every frame
void AUser_charachter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AUser_charachter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AUser_charachter::Call_fire()
{
	gun->OnFire();
}

