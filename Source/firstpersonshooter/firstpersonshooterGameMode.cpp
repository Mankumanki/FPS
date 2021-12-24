// Copyright Epic Games, Inc. All Rights Reserved.

#include "firstpersonshooterGameMode.h"
#include "firstpersonshooterHUD.h"
#include "firstpersonshooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AfirstpersonshooterGameMode::AfirstpersonshooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("D://unreal_engine_projects//firstpersonshooter//Content//FirstPerson//FP_Mesh//Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AfirstpersonshooterHUD::StaticClass();
}
