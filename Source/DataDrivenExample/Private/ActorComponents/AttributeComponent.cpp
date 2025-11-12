// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorComponents/AttributeComponent.h"
#include "DataAssets/DefaultPlayerAtrributeDataAsset.h"


void UAttributeComponent::BeginPlay()
{
	Super::BeginPlay();

	ensure(DefaultPlayerAttributeDataAsset);

	Health = DefaultPlayerAttributeDataAsset->MaxHealth;
}


void UAttributeComponent::ReduceHealthValueByDamageTypeAndDeltaValue(const float DamageValue, const EDamageType DamageType)
{
	const float OldHealth = Health;

	checkf(DefaultPlayerAttributeDataAsset != nullptr, TEXT("DefaultPlayerAttributeDataAsset is Not Assinged"));

	const float MaxHealth = DefaultPlayerAttributeDataAsset->MaxHealth;

	Health = FMath::Clamp(Health - DamageValue, 0.f, MaxHealth);

	if (OnHealthChangedDelegate.IsBound())
	{
		OnHealthChangedDelegate.Broadcast(OldHealth, Health,DamageType);
	}
}


float UAttributeComponent::GetHealthAttribute() const
{
	return Health;
}

