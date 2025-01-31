// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller_StartMenu.h"
#include "UObject/ConstructorHelpers.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "KidKingPlayerState.h"
#include "AbilitySystemComponent.h"
//#include "CharacterBase.h"

AController_StartMenu::AController_StartMenu()
{

	//isShowPauseMenu = false;
	//isShowCredits = false;

	//static ConstructorHelpers::FClassFinder<UUserWidget> GamePauseUI(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UI/Pause_BP.Pause_BP_C'"));
	//if (GamePauseUI.Succeeded())
	//{
	//	uiGamePauseBPClass = GamePauseUI.Class;
	//}

	//static ConstructorHelpers::FClassFinder<UUserWidget> GameCreditsUI(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UI/Credits_BP.Credits_BP_C'"));
	//if (GameCreditsUI.Succeeded())
	//{
	//	uiCreditsBPClass = GameCreditsUI.Class;
	//}

	//static ConstructorHelpers::FClassFinder<UUserWidget> DieUI(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UI/DieUI_BP.DieUI_BP_C'"));
	//if (DieUI.Succeeded())
	//{
	//	uiDieBPClass = DieUI.Class;
	//}

	//static ConstructorHelpers::FClassFinder<UUserWidget> FinalStageDieUI(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UI/FinalStageLoser.FinalStageLoser_C'"));
	//if (FinalStageDieUI.Succeeded())
	//{
	//	uiFinalStageDieBPClass = FinalStageDieUI.Class;
	//}

}

void AController_StartMenu::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AKidKingPlayerState* PS = GetPlayerState<AKidKingPlayerState>();
	if (PS)
	{
		PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, InPawn);
	}

}

void AController_StartMenu::SetupInputComponent()
{
	APlayerController::SetupInputComponent();

	InputComponent->BindAction(TEXT("Pause_UI"), EInputEvent::IE_Pressed, this, &AController_StartMenu::ShowPauseMenu);
	

}

void AController_StartMenu::ShowPauseMenu()
{
	SetInputMode(FInputModeUIOnly());

	if(uiGamePauseBPClass && isShowPauseMenu == false)
	{
		uiPauseMenuWidget = CreateWidget<UUserWidget>(GetWorld(), uiGamePauseBPClass);
		if (uiPauseMenuWidget)
		{
			uiPauseMenuWidget->AddToViewport();
		}
		isShowPauseMenu = true;
		//bShowMouseCursor = true;
	}

}

void AController_StartMenu::ClosePauseMenu()
{
	uiPauseMenuWidget->RemoveFromParent();
	isShowPauseMenu = false;
	bShowMouseCursor = false;
	SetInputMode(FInputModeGameOnly());
}

void AController_StartMenu::ShowCredits()
{
	if (uiCreditsBPClass && isShowCredits == false)
	{
		uiCreditsWidget = CreateWidget<UUserWidget>(GetWorld(), uiCreditsBPClass);

		if (uiCreditsWidget)
		{
			uiCreditsWidget->AddToViewport();
		}
		isShowCredits = true;
	}
}

void AController_StartMenu::CloseCredits()
{
	uiCreditsWidget->RemoveFromParent();
	isShowCredits = false;
}

void AController_StartMenu::ShowDieUI()
{
	if (uiDieBPClass)
	{
		uiDieWidget = CreateWidget<UUserWidget>(GetWorld(), uiDieBPClass);

		if (uiDieWidget)
		{
			uiDieWidget->AddToViewport();

		}
	}
}

void AController_StartMenu::ShowFinalStageDieUI()
{
	if (uiFinalStageDieBPClass)
	{
		uiFinalStageDieWidget = CreateWidget<UUserWidget>(GetWorld(), uiFinalStageDieBPClass);

		if (uiFinalStageDieWidget)
		{
			uiFinalStageDieWidget->AddToViewport();

		}
	}

}
