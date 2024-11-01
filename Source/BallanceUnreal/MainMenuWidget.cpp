#include "MainMenuWidget.h"
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


 