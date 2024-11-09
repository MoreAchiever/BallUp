#include "InGameHUDWidget.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h" 
#include "GameManager.h" 
#include <string> 


void UInGameHUDWidget::NativeConstruct()
{
    Super::NativeConstruct();
    CurrentScore = 0;  // Initialize current score
    getCoins();

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

        //ScoreTextBlock->SetText(FText::Format(FText::FromString("{0}/100"), FText::AsNumber(CurrentScore)));
        ScoreTextBlock->SetText(FText::Format(FText::FromString(FString::Printf(TEXT("{0}/%d"), TotalCoinsInLevel)),FText::AsNumber(CurrentScore)));
    }
    
    if (CurrentScore == TotalCoinsInLevel) // We need to change to the current amount of existing objects from static class ACoin
    {
        if (GameManager)
        {
            GameManager->NextLevel(); // Call the method from GameManager to load the main menu
        }
    }

}

void UInGameHUDWidget::getCoins() 
{
    TArray<AActor*> FoundCoins;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACoin::StaticClass(), FoundCoins);
    TotalCoinsInLevel = FoundCoins.Num();
}
