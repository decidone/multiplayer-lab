#include "SharedCube.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Net/UnrealNetwork.h"

ASharedCube::ASharedCube()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;

    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(
        TEXT("CubeMesh"));

    SetRootComponent(CubeMesh);
    CubeMesh->SetCollisionProfileName(TEXT("BlockAll"));
}

void ASharedCube::BeginPlay()
{
    Super::BeginPlay();

    ApplyVisualState();
}

void ASharedCube::ApplyVisualState()
{
    UMaterialInterface* SelectedMaterial =
        bIsActive ? ActiveMaterial.Get() : InactiveMaterial.Get();

    if (IsValid(CubeMesh) && IsValid(SelectedMaterial))
    {
        CubeMesh->SetMaterial(0, SelectedMaterial);
    }
}

void ASharedCube::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASharedCube, bIsActive);
}

void ASharedCube::ToggleActive()
{
    // 상태 변경은 서버에서만 허용
    if (!HasAuthority())
    {
        return;
    }

    bIsActive = !bIsActive;

    ApplyVisualState();
}

void ASharedCube::OnRep_IsActive()
{
    ApplyVisualState();
}