#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovableGround.generated.h"

UCLASS()
class BALLANCEUNREAL_API AMovableGround : public AActor
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

public:
    // Sets default values for this actor's properties
    AMovableGround();

    virtual void Tick(float DeltaTime) override;

    // Movement properties
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MoveSpeed = 100.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    FVector MoveDirection = FVector(0, 0, 1);

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MoveDistance = 500.0f;

    // Box component for collision
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UBoxComponent* BoxComponent;

    // Cube mesh for visual representation
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UStaticMeshComponent* CubeMesh;

private:
    FVector StartLocation;
    bool bMovingForward = true;
};
