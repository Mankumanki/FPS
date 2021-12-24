// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "firstpersonshooterHUD.generated.h"

UCLASS()
class AfirstpersonshooterHUD : public AHUD
{
	GENERATED_BODY()

public:
	AfirstpersonshooterHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

