#include "SpherePawn.h"
#include "Kismet/GameplayStatics.h"

ASpherePawn::ASpherePawn()
{
    PrimaryActorTick.bCanEverTick = true;

    // Initialize components
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    SetRootComponent(SphereComponent);
    SphereComponent->SetSphereRadius(50.0f);

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->SetupAttachment(SphereComponent);
    SpringArm->TargetArmLength = 300.0f;
    SpringArm->bUsePawnControlRotation = true;

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"));
    FloatingPawnMovement->MaxSpeed = 1000.0f;
    FloatingPawnMovement->Acceleration = 2000.0f;
    FloatingPawnMovement->Deceleration = 2000.0f;
}

void ASpherePawn::BeginPlay()
{
    Super::BeginPlay();

    AActor* SphereActor = nullptr;
    TArray<AActor*> FoundActors;

    // Find the first actor with the tag "MySphere"
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), TEXT("WSphere"), FoundActors);

    if (FoundActors.Num() > 0)
    {
        SphereActor = FoundActors[0];  // Only use the first actor
        if (SphereActor)
        {
            UE_LOG(LogTemp, Warning, TEXT("Found sphere actor: %s"), *SphereActor->GetName());
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No actor found with tag 'MySphere'"));
    }
}

void ASpherePawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ASpherePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &ASpherePawn::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &ASpherePawn::MoveRight);
}

void ASpherePawn::MoveForward(float Value)
{

    UE_LOG(LogTemp, Warning, TEXT("MoveForward Value: %f"), Value);
    AddMovementInput(GetActorForwardVector(), Value);

}

void ASpherePawn::MoveRight(float Value)
{

    UE_LOG(LogTemp, Warning, TEXT("MoveRight Value: %f"), Value);
    AddMovementInput(GetActorRightVector(), Value);

}

