// Fill out your copyright notice in the Description page of Project Settings.

#include "GhostHolidayStoryGameModeBase.h"
#include "Public/MainPawn.h"
#include "Public/MainGameState.h"
#include "Engine/World.h"
#include "Array.h"
#include "EngineUtils.h"
#include "GameFramework/Actor.h"

#include "Runtime/XmlParser/Public/XmlParser.h"
#include "Runtime/XmlParser/Public/FastXml.h" 
#include "XmlParser/Public/XmlFile.h"
#include "Paths.h"

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

	LoadGreetingsFromXML();
}

void AGhostHolidayStoryGameModeBase::EnterStudio()
{
	if (mainGameState->GetMainGameStateEnum() == MainGameStateEnum::Outdoor)
	{
		mainGameState->SetMainGameStateEnum(MainGameStateEnum::ChangeConfig);
		mainPawn->EnterStudio();
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

FTalkGroup AGhostHolidayStoryGameModeBase::GetRandomGreetingsTalkGroup()
{
	int index = (int)(((float)FMath::Rand() / RAND_MAX)*greetingsList.Num());
	return greetingsList[index];
}

FTalkGroup AGhostHolidayStoryGameModeBase::GetRandomClosingsTalkGroup()
{
	int index = (int)(((float)FMath::Rand() / RAND_MAX)*closingsList.Num());
	return closingsList[index];
}

FString AGhostHolidayStoryGameModeBase::GetCommonPath()
{
	return FPaths::ProjectContentDir() + relativeCommonPath;
}

FString AGhostHolidayStoryGameModeBase::GetRelativeCommonPath()
{
	return relativeCommonPath;
}

void AGhostHolidayStoryGameModeBase::LoadGreetingsFromXML()
{
	greetingsList.Empty();
	FXmlFile* xmlFile = new FXmlFile(GetCommonPath() + TEXT("Greetings.xml"));
	FXmlNode* rootNode = xmlFile->GetRootNode();

	const TArray<FXmlNode*> nodeList = rootNode->GetChildrenNodes();

	for (FXmlNode* groupNode : nodeList)
	{
		FString imagePath = groupNode->GetAttribute(TEXT("image"));

		FTalkGroup talkGroup;
		talkGroup.imagePath = imagePath;

		const TArray<FXmlNode*> itemList = groupNode->GetChildrenNodes();

		FXmlNode* node0 = itemList[0];
		FString tempText0 = node0->GetAttribute(TEXT("text"));
		FString tempAudio0 = node0->GetAttribute(TEXT("audio"));
		talkGroup.talk0.text = tempText0;
		talkGroup.talk0.audio = tempAudio0;

		FXmlNode* node1 = itemList[1];
		FString tempText1 = node1->GetAttribute(TEXT("text"));
		FString tempAudio1 = node1->GetAttribute(TEXT("audio"));
		talkGroup.talk1.text = tempText1;
		talkGroup.talk1.audio = tempAudio1;
		greetingsList.Add(talkGroup);
	}
}

void AGhostHolidayStoryGameModeBase::LoadClosingsFromXML()
{
	closingsList.Empty();
	FXmlFile* xmlFile = new FXmlFile(GetCommonPath() +TEXT("Closings.xml"));
	FXmlNode* rootNode = xmlFile->GetRootNode();

	const TArray<FXmlNode*> nodeList = rootNode->GetChildrenNodes();
	
	for (FXmlNode* groupNode : nodeList)
	{
		FString imagePath = groupNode->GetAttribute(TEXT("image"));

		FTalkGroup talkGroup;
		talkGroup.imagePath = imagePath;

		const TArray<FXmlNode*> itemList = groupNode->GetChildrenNodes();

		FXmlNode* node0 = itemList[0];
		FString tempText0 = node0->GetAttribute(TEXT("text"));
		FString tempAudio0 = node0->GetAttribute(TEXT("audio"));
		talkGroup.talk0.text = tempText0;
		talkGroup.talk0.audio = tempAudio0;

		FXmlNode* node1 = itemList[1];
		FString tempText1 = node1->GetAttribute(TEXT("text"));
		FString tempAudio1 = node1->GetAttribute(TEXT("audio"));
		talkGroup.talk1.text = tempText1;
		talkGroup.talk1.audio = tempAudio1;

		closingsList.Add(talkGroup);
	}
}

