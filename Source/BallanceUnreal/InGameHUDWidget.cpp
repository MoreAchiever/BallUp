#include "InGameHUDWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h" // Include for UGameplayStatics
#include "GameManager.h" // Include your GameManager header

void UInGameHUDWidget::NativeConstruct()
{
    Super::NativeConstruct();
    CurrentScore = 0;  // Initialize current score

    // Get the GameManager instance
    GameManager = Cast<AGameManager>(UGameplayStatics::GetGameMode(this));
    if (!GameManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("GameManager not found! Make sure it's set in the level."));
    }


    // Bind the button click event
    if (ReturnToMainMenuButton)
    {
        ReturnToMainMenuButton->OnClicked.AddDynamic(this, &UInGameHUDWidget::OnReturnToMainMenu);
    }
}

void UInGameHUDWidget::OnReturnToMainMenu()
{
    if (GameManager)
    {
        GameManager->ReturnToMainMenu(); // Call the method from GameManager to load the main menu
    }
}

void UInGameHUDWidget::UpdateScore(int32 NewScore)
{
    CurrentScore = NewScore;
    UE_LOG(LogTemp, Log, TEXT("Current Score: %d"), CurrentScore);
    // Assuming ScoreTextBlock is properly bound in the Blueprint
    if (ScoreTextBlock)
    {
        ScoreTextBlock->SetText(FText::Format(FText::FromString("{0}/100"), FText::AsNumber(CurrentScore)));
    }
    if (CurrentScore == 2) 
    {
        if (GameManager)
        {
            GameManager->NextLevel(); // Call the method from GameManager to load the main menu
        }
    }

}
