#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "GameManager.h"
#include "Coin.h"
#include "InGameHUDWidget.generated.h"


/**
 * InGameHUDWidget class for displaying the in-game UI.
 */
UCLASS()
class BALLANCEUNREAL_API UInGameHUDWidget : public UUserWidget
{
    GENERATED_BODY()

public:

  
    // Reference to the GameMode  
    UPROPERTY()
    AGameManager* GameManager;

    // Function to bind button click event
    UFUNCTION(BlueprintCallable, Category = "UI")
    void OnReturnToMainMenu();



protected:
    virtual void NativeConstruct() override;

public:

  

    // Button to return to the main menu (set this in the UI designer)
    UPROPERTY(meta = (BindWidget))
    UButton* ReturnToMainMenuButton;

    // Method to update the score display
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateScore(int32 NewScore);

    void getCoins();

    UPROPERTY(meta = (BindWidget))
    UTextBlock* ScoreTextBlock;
 
private:
    int32 CurrentScore;

    int32 TotalCoinsInLevel;
};
