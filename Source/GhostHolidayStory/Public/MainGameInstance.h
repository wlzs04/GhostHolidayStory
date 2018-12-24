// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

class USoundBase; 
class UPaperSprite;

/**
 * 
 */
UCLASS()
class GHOSTHOLIDAYSTORY_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	USoundBase* LoadSound(FString dictoryPath, FString audioName);

	UFUNCTION(BlueprintCallable)
	UPaperSprite* LoadSprite(FString dictoryPath, FString audioName);
};
