// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"

class UDefaultPlayerAtrributeDataAsset;
class USoundCue;
class UNiagaraSystem;

UENUM(BlueprintType)
enum class EDamageType : uint8
{
	EDT_LightDamage,
	EDT_MidDamage,
	EDT_HeavyDamage,
	MAX UMETA(Hidden)
};

USTRUCT(BlueprintType)
struct FDamageData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	float DamageValue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<USoundCue> DamageSFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UNiagaraSystem> DamageVFX;

};



DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnHealthChanged, float, OldHealth, float, NewHealth,EDamageType,DamageType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DATADRIVENEXAMPLE_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void ReduceHealthValueByDamageTypeAndDeltaValue(const float DamageValue, const EDamageType DamageType = EDamageType::EDT_LightDamage);

	UFUNCTION(BlueprintPure)
	float GetHealthAttribute() const;

	UPROPERTY(BlueprintAssignable)
	FOnHealthChanged OnHealthChangedDelegate;


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UDefaultPlayerAtrributeDataAsset> DefaultPlayerAttributeDataAsset;


protected:

	virtual void BeginPlay() override;

private:

	float Health;

	
};
