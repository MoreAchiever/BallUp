#include "GameManager.h"
#include "Kismet/GameplayStatics.h"
#include "SpherePawn.h"
#include "UMainMenuWidget.h"

AGameManager::AGameManager()
{
    // Set default values
    MainMenuWidgetClass = nullptr; // Set this in the editor to your UMainMenuWidget Blueprint
    // Set the default pawn class to ASpherePawn
    DefaultPawnClass = ASpherePawn::StaticClass();
}

void AGameManager::BeginPlay()
{
    Super::BeginPlay();

    // Check if we should show the main menu
    if (MainMenuWidgetClass)
    {
        // Initialize and display the main menu widget
        InitializeMainMenuWidget();
        
    }

    // Set the default pawn class to ASpherePawn
    if (GetWorld())
    {
        UWorld* World = GetWorld();
        World->GetAuthGameMode()->DefaultPawnClass = ASpherePawn::StaticClass();
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
    // Logic to pause the game
    UGameplayStatics::SetGamePaused(GetWorld(), true);
}

void AGameManager::ClearMainMenu()
{
    UE_LOG(LogTemp, Warning, TEXT("Clearing main menu widget..."));
    if (MainMenuWidget)
    {
        UE_LOG(LogTemp, Warning, TEXT("Clearing main menu widget..."));
        MainMenuWidget->RemoveFromViewport();
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
    UE_LOG(LogTemp, Warning, TEXT("..."));
    UGameplayStatics::OpenLevel(this, FName(TEXT("NewWorld")));
    
    if (GetWorld())
    {
        UWorld* World = GetWorld();
        World->GetAuthGameMode()->DefaultPawnClass = ASpherePawn::StaticClass();
    }

    // Call the function to spawn the player pawn at the desired location
    SpawnPlayerPawn();
}

void AGameManager::QuitGame()
{
    // Logic to quit the game
    UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, false);
}

void AGameManager::ReturnToMainMenu()
{
    // Load the main menu level (replace "MainMenuLevel" with your main menu level name)
    UGameplayStatics::OpenLevel(this, FName(TEXT("MainMenuLevel")));
}

void AGameManager::NextLevel()
{
    // Logic to go to the next level
    // You can define your own logic for level progression here
    UGameplayStatics::OpenLevel(this, FName(TEXT("NextLevel"))); // Replace with actual level name
}
