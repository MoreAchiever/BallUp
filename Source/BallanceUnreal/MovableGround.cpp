#include "MovableGround.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AMovableGround::AMovableGround()
{
    PrimaryActorTick.bCanEverTick = true;

    // Create and set up the box component as the root
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
    RootComponent = BoxComponent;
    BoxComponent->SetBoxExtent(FVector(100.0f, 100.0f, 10.0f)); // Set the size of the box
    BoxComponent->SetCollisionProfileName(TEXT("BlockAllDynamic")); // Set a collision profile

    // Create and set up the cube mesh component as a child of the box component
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    CubeMesh->SetupAttachment(BoxComponent);

    // Assign a default cube mesh
    /*static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Engine/BasicShapes/Cube"));*/
    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeAsset(TEXT("/Content/Bazaar_Meshingun/Environment/Assets/Mesh/Architecture/SM_Dome_02a"));
    if (CubeAsset.Succeeded())
    {
        CubeMesh->SetStaticMesh(CubeAsset.Object);
        CubeMesh->SetRelativeScale3D(FVector(2.0f, 2.0f, 0.5f)); // Scale the cube to desired size
    }
}

// Called when the game starts or when spawned
void AMovableGround::BeginPlay()
{
    Super::BeginPlay();
    StartLocation = GetActorLocation();
}

// Called every frame
void AMovableGround::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector CurrentLocation = GetActorLocation();
    float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);

    if (DistanceMoved >= MoveDistance)
    {
        bMovingForward = !bMovingForward;
    }

    FVector Direction = (bMovingForward ? 1 : -1) * MoveDirection;
    CurrentLocation += Direction * MoveSpeed * DeltaTime;
    SetActorLocation(CurrentLocation);
}
