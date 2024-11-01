#include "Coin.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
 

// Sets default values
ACoin::ACoin()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;

    // Create and configure the sphere component for collision
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    RootComponent = SphereComponent;
    SphereComponent->SetSphereRadius(50.0f); // Adjust radius as needed
    SphereComponent->SetCollisionProfileName(TEXT("OverlapAll")); // Set to overlap with all objects
    SphereComponent->SetGenerateOverlapEvents(true); // Enable overlap events

    // Create and configure the static mesh component
    CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CoinMesh"));
    CoinMesh->SetupAttachment(SphereComponent);
    CoinMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision); // Disable collision for visual mesh

    //// Bind overlap event
    //SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ACoin::OnOverlapBegin);
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Define the rotation rate
    FRotator RotationRate = FRotator(0.f, 0.f, 50.f * DeltaTime); // Adjust Yaw speed as needed

    // Apply rotation
    CoinMesh->AddLocalRotation(RotationRate);
}
 