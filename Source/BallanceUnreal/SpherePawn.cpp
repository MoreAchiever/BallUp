#include "SpherePawn.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/PlayerInput.h" // For input binding

// Constructor
ASpherePawn::ASpherePawn()
{
    // Set this pawn to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;

    // Initialize Sphere Component (for collision and physics)
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    SetRootComponent(SphereComponent);
    SphereComponent->SetSphereRadius(50.0f);
    SphereComponent->SetSimulatePhysics(true); // Enable physics simulation
    SphereComponent->SetCollisionProfileName(TEXT("Pawn")); // Use 'Pawn' collision preset
    SphereComponent->SetEnableGravity(true); // Enable gravity

    // Initialize Static Mesh Component (for visual representation)
    BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
    BallMesh->SetupAttachment(SphereComponent);
    BallMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision); // Disable collision for visual mesh
    BallMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f)); // Adjust scale as needed

    // Initialize Spring Arm Component (for camera)
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
    SpringArm->TargetArmLength = 500.f; // Distance from the ball to the camera
    SpringArm->bUsePawnControlRotation = true; // Allow camera rotation with the player
    SpringArm->SetupAttachment(SphereComponent);

    // Initialize Camera Component
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->bUsePawnControlRotation = false; // Keep camera rotation separate from pawn
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    // Default values for jump and dash
    JumpForce = 800.f;
    DashForce = 30.f;
    MaximumSpeed = 100.f;
    ControllerForce = 1500.f; // Force applied based on player input
    DashTimer = 0.f;

    // Initialize input variables
    InputLongitude = 0.f;
    InputLatitude = 0.f;
    bInContact = false; // Initialize contact state to false

 
}

// Setup input bindings
void ASpherePawn::InitializeDefaultPawnInputBindings()
{
    static bool bBindingsAdded = false;
    if (bBindingsAdded) return;
    bBindingsAdded = true;

    UE_LOG(LogTemp, Warning, TEXT("Adding Bindings!"));
    UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_LookUp", EKeys::MouseY, -1.f));
    UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_LookRight", EKeys::MouseX, 1.f));
    UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLongitudinally", EKeys::W, 1.f));
    UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLongitudinally", EKeys::S, -1.f));
    UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLaterally", EKeys::A, -1.f));
    UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("BallBearing_MoveLaterally", EKeys::D, 1.f));
    UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("BallBearing_Jump", EKeys::SpaceBar));
    UPlayerInput::AddEngineDefinedActionMapping(FInputActionKeyMapping("BallBearing_Dash", EKeys::LeftShift));
}

void ASpherePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    InitializeDefaultPawnInputBindings();
    PlayerInputComponent->BindAxis("BallBearing_LookUp", this, &ASpherePawn::LookUp);
    PlayerInputComponent->BindAxis("BallBearing_LookRight", this, &ASpherePawn::LookRight);
    PlayerInputComponent->BindAxis("BallBearing_MoveLongitudinally", this, &ASpherePawn::MoveLongitudinally);
    PlayerInputComponent->BindAxis("BallBearing_MoveLaterally", this, &ASpherePawn::MoveLaterally);
    PlayerInputComponent->BindAction("BallBearing_Jump", EInputEvent::IE_Pressed, this, &ASpherePawn::Jump);
    PlayerInputComponent->BindAction("BallBearing_Dash", EInputEvent::IE_Pressed, this, &ASpherePawn::Dash);
}

void ASpherePawn::BeginPlay()
{
    Super::BeginPlay();
 
}



void ASpherePawn::Jump()
{
    if ( bCanJump) // Check if in contact and can jump
    {
        // Apply an upward impulse when the ball is in contact with the ground
        float CurrentMass = SphereComponent->GetMass();
        FVector Impulse = FVector(0, 0, JumpForce * CurrentMass);
        SphereComponent->AddImpulse(Impulse);

        // Start the cooldown timer
        bCanJump = false; // Set flag to false to prevent further jumps
        GetWorld()->GetTimerManager().SetTimer(JumpCooldownTimerHandle, this, &ASpherePawn::ResetJump, 1.0f, false);
    }
}

void ASpherePawn::ResetJump()
{
    bCanJump = true; // Allow jumping again after the cooldown
}

void ASpherePawn::Dash()
{
    if (DashTimer <= 0)
    {
        FVector Velocity = SphereComponent->GetPhysicsLinearVelocity();
        if (Velocity.Size() > 100.f) // Ensure the velocity is above a threshold
        {
            Velocity.Normalize();
            Velocity *= DashForce * 100.f; // Dash force applied
            SphereComponent->AddImpulse(Velocity);
            DashTimer = 1.15f; // Set cooldown for dash
        }
    }
}
void ASpherePawn::RestartGame()
{
    UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false); // Restart the current level
}

void ASpherePawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Handling input for movement and setting velocities
    FRotator ControlRotation = FRotator(0, GetControlRotation().Yaw, 0);
    FRotationMatrix ControlMatrix(ControlRotation);
    FVector ForwardDirection = ControlMatrix.GetUnitAxis(EAxis::X);
    FVector RightDirection = ControlMatrix.GetUnitAxis(EAxis::Y);

    // Get current velocity and maintain Z component for jumping
    FVector Velocity = SphereComponent->GetPhysicsLinearVelocity();
    float Z = Velocity.Z;

    // Cap the speed of the ball
    if (Velocity.Size() > MaximumSpeed * 100.f) // Maximum Speed is in m/s
    {
        Velocity.Normalize();
        Velocity *= MaximumSpeed * 100.f; // Scale velocity to maximum speed
        Velocity.Z = Z; // Maintain the Z component (for jumping)
        SphereComponent->SetPhysicsLinearVelocity(Velocity); // Set the new capped velocity
    }
    else
    {
        // Apply force based on player input
        SphereComponent->AddForce((InputLatitude * RightDirection + InputLongitude * ForwardDirection) * ControllerForce * SphereComponent->GetMass());
    }

    // Update Dash Timer
    if (DashTimer > 0)
    {
        DashTimer = FMath::Max(0.f, DashTimer - DeltaTime);
    }

    // Set the start and end points for the sphere trace
    FVector Start = GetActorLocation(); // Starting point at the pawn's location
    FVector End = Start - FVector(0, 0, 100); // Trace 100 units downward
    float SphereRadius = 50.0f; // Radius of the sphere

    FHitResult HitResult;
    FCollisionQueryParams CollisionParams;

    // Check if the ball falls below a certain height
    if (SphereComponent->GetComponentLocation().Z < -500) // Set a suitable threshold
    {
        RestartGame(); // Call function to restart the game
    }
}

// Input handling methods
void ASpherePawn::LookUp(float Value)
{
    // Implement camera look up/down functionality if necessary
}

void ASpherePawn::LookRight(float Value)
{
    // Implement camera look left/right functionality if necessary
}

void ASpherePawn::MoveLongitudinally(float Value)
{
    InputLongitude = Value; // Store input value for longitudinal movement
}

void ASpherePawn::MoveLaterally(float Value)
{
    InputLatitude = Value; // Store input value for lateral movement
}
