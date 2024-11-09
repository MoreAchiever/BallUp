#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Engine/StaticMeshActor.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h" 
#include "InGameHUDWidget.h" 
#include "Coin.h" 
#include "SpherePawn.generated.h"


UCLASS()
class BALLANCEUNREAL_API ASpherePawn : public APawn
{
    GENERATED_BODY()

public:
    ASpherePawn();

    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // Input handling
    void MoveLongitudinally(float Value);
    void MoveLaterally(float Value);
    void Jump();
    void Dash();

    void ResetJump(); // Declare the ResetJump function
    void RestartGame(); // Function to restart the game

    // Variable to hold the HUD widget class
    UPROPERTY(EditAnywhere, Category = "UI")
    TSubclassOf<UUserWidget> InGameHUDWidgetClass;

    // Score variable
    UPROPERTY(BlueprintReadOnly, Category = "Score")
    int32 Score;

    // Reference to the HUD widget
    UPROPERTY()
    UInGameHUDWidget* InGameHUDWidget;

    // Function to update the score
    void UpdateScore(int32 NewScore);

    // Collision handling function
    UFUNCTION()
    void OnCoinCollected(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    // Sound Cue for collecting the coin
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    class USoundBase* CollectionSound;

protected:
    virtual void BeginPlay() override;

    // Camera rotation functions
    void StartRotateLeft();
    void StopRotateLeft();
    void StartRotateRight();
    void StopRotateRight();
    void UpdateCameraRotation(float DeltaTime);

private:
    FTimerHandle JumpCooldownTimerHandle; // Timer handle for managing jump cooldown
    bool bCanJump = true; // Flag to determine if the pawn can jump

    //camera rotation variables:
    float CameraRotationSpeed = 90.0f; // Degrees per second
    bool bRotatingLeft = false;
    bool bRotatingRight = false;

    void InitializeDefaultPawnInputBindings(); // Declare the function

    // Sphere Component for collision and physics simulation
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USphereComponent* SphereComponent;

    // Static Mesh for the visual representation of the ball
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UStaticMeshComponent* BallMesh;

    // Spring Arm and Camera for following the ball
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    USpringArmComponent* SpringArm;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UCameraComponent* Camera;

    // Movement Component
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
    UFloatingPawnMovement* FloatingPawnMovement;

    // Movement Input functions
    void MoveForward(float Value);
    void MoveRight(float Value);

    // Input variables
    float InputLongitude; // For forward/backward movement
    float InputLatitude;  // For left/right movement

    // Jumping and dashing variables
    float JumpForce;
    float DashForce;
    float MaximumSpeed;
    float ControllerForce;
    float DashTimer;

};
