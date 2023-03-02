// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RespawnBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class URespawnBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
protected:
	// call when player died
	static void RegisterRespawn(class ACharacterPawn* Character);

public:


};
