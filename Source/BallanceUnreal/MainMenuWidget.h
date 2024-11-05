//MainMenuWidget.h

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

UCLASS()
class BALLANCEUNREAL_API UMainMenuWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    // Override the NativeConstruct method
    virtual void NativeConstruct() override;

protected:
    // Bindable function for Start and Quit button clicks
    UFUNCTION()
    void StartGame();

    UFUNCTION()
    void QuitGame();

    // UI elements to bind
    UPROPERTY(meta = (BindWidget))
    class UButton* StartButton;

    UPROPERTY(meta = (BindWidget))
    class UButton* QuitButton;
};
