// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DefaultPlayerAtrributeDataAsset.generated.h"

class UNiagaraSystem;

UCLASS()
class DATADRIVENEXAMPLE_API UDefaultPlayerAtrributeDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", ClampMax = "100"))
	float MaxHealth = 100.f;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	TObjectPtr<UDataTable> DamageTypeDataTable;
};
