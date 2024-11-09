#include "GameManager.h"
#include "Kismet/GameplayStatics.h"
#include "SpherePawn.h"
#include "MainMenuWidget.h"
#include "Sound/SoundBase.h"

AGameManager::AGameManager()
{
    MainMenuWidgetClass = nullptr; // Set this in the editor to your UMainMenuWidget Blueprint
}

void AGameManager::BeginPlay()
{
    Super::BeginPlay();

    // Check if we should show the main menu
    if (MainMenuWidgetClass)
    {
        // Get the current level name
        FString CurrentLevelName = UGameplayStatics::GetCurrentLevelName(GetWorld());

        // Only initialize the main menu if we are in the "MainMenu" level
        if (CurrentLevelName == "MainMenuLevel")
        {
            // Initialize and display the main menu widget
            InitializeMainMenuWidget();
        }
    }
}

void AGameManager::InitializeMainMenuWidget()
{
    // Create an instance of the main menu widget
    if (MainMenuWidgetClass)
    {
        MainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
        // Logic to show the main menu
        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();
        }
    }
}

void AGameManager::GoToMainMenu()
{
    // Logic to show the main menu
    if (MainMenuWidget)
    {
        MainMenuWidget->AddToViewport();
    }

}


void AGameManager::PauseGame()
{
    UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void AGameManager::ClearMainMenu()
{
    if (MainMenuWidget)
    {
        MainMenuWidget->RemoveFromParent();
        MainMenuWidget = nullptr;
    }
}

void AGameManager::SpawnPlayerPawn()
{
    if (GetWorld())
    {
        // Define the desired spawn location and rotation
        FVector SpawnLocation = FVector(0.0f, 0.0f, 50.0f); // Adjust as needed
        FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f); // Adjust rotation if needed

        // Spawn the ASpherePawn
        ASpherePawn* PlayerPawn = GetWorld()->SpawnActor<ASpherePawn>(ASpherePawn::StaticClass(), SpawnLocation, SpawnRotation);

        if (PlayerPawn)
        {
            // Possess the pawn with the player controller
            APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
            if (PlayerController)
            {
                PlayerController->Possess(PlayerPawn);
            }
        }
    }
}

void AGameManager::StartGame()
{
    ClearMainMenu(); // Clear the main menu before starting the game
    
    // Load the first level (replace "FirstLevel" with the actual level name)
    UGameplayStatics::OpenLevel(this, FName(TEXT("NewWorld")));

}

void AGameManager::QuitGame()
{
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}

void AGameManager::ReturnToMainMenu()
{
    // Load the main menu level (replace "MainMenuLevel" with your main menu level name)
    UGameplayStatics::OpenLevel(this, FName(TEXT("MainMenuLevel")));
}

void AGameManager::NextLevel()
{
    
    // Play the NextLevelSound  
    if (NextLevelSound)
    {
        UGameplayStatics::PlaySound2D(this, NextLevelSound);
    }

    // Set a timer to call the ChangeLevel function after a short delay (e.g., 1 second)
    float DelayDuration = 1.0f; // Delay before changing level
    GetWorld()->GetTimerManager().SetTimerForNextTick([this, DelayDuration]()
        {
            GetWorld()->GetTimerManager().SetTimer(TransitionTimer, this, &AGameManager::ChangeLevel, DelayDuration, false);
        });
  
}

// Function to change levels
void AGameManager::ChangeLevel()
{
    UGameplayStatics::OpenLevel(this, FName(TEXT("MainMenuLevel"))); // Replace with actual level name
}
