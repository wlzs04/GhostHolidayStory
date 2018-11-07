// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostHolidayStoryGameModeBase.h"
#include "Public/MainPawn.h"
#include "Public/MainGameState.h"
#include "Engine/World.h"
#include "Array.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"

AGhostHolidayStoryGameModeBase::AGhostHolidayStoryGameModeBase()
{
	this->GameStateClass = AMainGameState::StaticClass();
	this->DefaultPawnClass = AMainPawn::StaticClass();
}

void AGhostHolidayStoryGameModeBase::StartPlay()
{
	AGameModeBase::StartPlay();
	mainGameState = Cast<AMainGameState>(this->GameState);
	
	mainPawn = Cast<AMainPawn>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void AGhostHolidayStoryGameModeBase::EnterStudio()
{
	if (mainGameState->GetMainGameStateEnum() == MainGameStateEnum::Outdoor)
	{
		mainGameState->SetMainGameStateEnum(MainGameStateEnum::ChangeConfig);
		GetActorChildByName( GetActorByName(TEXT("Wall_Sprite4")), TEXT("Door_Sprite"))->SetActorRelativeRotation(FRotator(0,-90,0));
		mainPawn->ChangePlayerInput_ChangeConfig();
	}
}

AActor* AGhostHolidayStoryGameModeBase::GetActorByName(FString actorName)
{
	FString tempActorName;

	TActorIterator<AActor> actorItr = TActorIterator<AActor>(GetWorld());
	for (actorItr; actorItr; ++actorItr) 
	{
		if (actorItr) 
		{
			tempActorName = actorItr->GetActorLabel();
			if (tempActorName == actorName)
			{
				return *actorItr;
			}
		}
	}
	return nullptr;
}

AActor* AGhostHolidayStoryGameModeBase::GetActorChildByName(AActor* baseActor,FString actorName)
{
	TArray<AActor*> children;
	baseActor->GetAttachedActors(children);
	FString tempActorName;
	for (int i = 0; i < children.Num(); i++)
	{
		AActor*a = children[i];
		tempActorName = a->GetActorLabel();
		if (tempActorName == actorName)
		{
			return a;
		}
	}
	return nullptr;
}

