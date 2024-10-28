#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UMainMenuWidget.h" // Include your UMainMenuWidget header
#include "GameManager.generated.h"

/**
 * AGameManager class to handle game flow including the main menu and level transitions.
 */
UCLASS()
class BALLANCEUNREAL_API AGameManager : public AGameModeBase
{
    GENERATED_BODY()

public:
    // Constructor
    AGameManager();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Function to start the game
    UFUNCTION(BlueprintCallable, Category = "Game Management")
    void StartGame();

    UFUNCTION(BlueprintCallable, Category = "Game Management")
    void QuitGame();

    // Function to show the main menu
    UFUNCTION(BlueprintCallable, Category = "Game Management")
    void GoToMainMenu();

    // Function to pause the game
    UFUNCTION(BlueprintCallable, Category = "Game Management")
    void PauseGame();

    // Function to return to the main menu
    UFUNCTION(BlueprintCallable, Category = "Game Management")
    void ReturnToMainMenu();

    // Function to go to the next level
    UFUNCTION(BlueprintCallable, Category = "Game Management")
    void NextLevel();

    void ClearMainMenu(); // Add this function declaration

    void SpawnPlayerPawn();

protected:
    // Reference to the main menu widget
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UMainMenuWidget> MainMenuWidgetClass; // Class type of the main menu widget

    // Instance of the main menu widget
    UMainMenuWidget* MainMenuWidget; // Pointer to the actual widget instance

    // Initialize the main menu widget
    void InitializeMainMenuWidget();
};
