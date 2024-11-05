#include "MainMenuWidget.h"
#include "Components/Button.h"
#include "GameManager.h"
#include "Kismet/GameplayStatics.h"
//Neu eingefügt
#include "Kismet/KismetSystemLibrary.h"

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

// Add these implementations
void UMainMenuWidget::StartGame()
{
    // Implementation for starting the game
    UGameplayStatics::OpenLevel(GetWorld(), FName("NewWorld"));
}

void UMainMenuWidget::QuitGame()
{
    // Implementation for quitting the game
    UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, false);
}