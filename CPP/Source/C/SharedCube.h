#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SharedCube.generated.h"

class UStaticMeshComponent;
class UMaterialInterface;

UCLASS()
class C_API ASharedCube : public AActor
{
    GENERATED_BODY()

public:
    ASharedCube();
    virtual void GetLifetimeReplicatedProps(
        TArray<FLifetimeProperty>& OutLifetimeProps) const override;

    void ToggleActive();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Cube")
    TObjectPtr<UStaticMeshComponent> CubeMesh;

    UPROPERTY(
        EditAnywhere,
        BlueprintReadOnly,
        ReplicatedUsing = OnRep_IsActive,
        Category = "Cube"
    )
    bool bIsActive = false;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cube")
    TObjectPtr<UMaterialInterface> InactiveMaterial;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Cube")
    TObjectPtr<UMaterialInterface> ActiveMaterial;

    UFUNCTION()
    void OnRep_IsActive();

    void ApplyVisualState();
};