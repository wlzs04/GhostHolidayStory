// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "GhostHolidayStoryGameModeBase.generated.h"

class AMainGameState;
class AMainPawn;
/**
 * 
 */
UCLASS()
class GHOSTHOLIDAYSTORY_API AGhostHolidayStoryGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AGhostHolidayStoryGameModeBase();
	virtual void StartPlay() override;

	//进入放映室
	void EnterStudio();

	//通过名称获得actor
	AActor* GetActorByName(FString actorName);

	AActor* GetActorChildByName(AActor* baseActor,FString actorName);
	
private:

	AMainGameState* mainGameState;
	AMainPawn* mainPawn;
};
