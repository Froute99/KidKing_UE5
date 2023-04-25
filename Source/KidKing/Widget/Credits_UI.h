// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/Components/Button.h"
#include "Credits_UI.generated.h"

/**
 * 
 */
UCLASS()
class KIDKING_API UCredits_UI : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;

protected:

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		UButton* Btn_Credits_Close = nullptr;

	UFUNCTION(BlueprintCallable)
		void Btn_Credits_CloseWindow();
};
