#include "UMainMenuWidget.h"
#include "Components/Button.h"
#include "GameManager.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    // Bind the button click events
    if (StartButton)
    {
        StartButton->OnClicked.AddDynamic(this, &UMainMenuWidget::StartGame);
    }

    if (QuitButton)
    {
        QuitButton->OnClicked.AddDynamic(this, &UMainMenuWidget::QuitGame);
    }
}

void UMainMenuWidget::StartGame()
{
    // Get the GameManager instance and call StartGame()
    if (AGameManager* GameManager = Cast<AGameManager>(UGameplayStatics::GetGameMode(this)))
    {
        if (GameManager)
        {
            GameManager->StartGame(); // Call the StartGame method from GameManager
        }
    }
}

void UMainMenuWidget::QuitGame()
{
    // Get the GameManager instance and call QuitGame()
    if (AGameManager* GameManager = Cast<AGameManager>(UGameplayStatics::GetGameMode(this)))
    {
        if (GameManager)
        {
            GameManager->QuitGame(); // Call the QuitGame method from GameManager
        }
    }
}
