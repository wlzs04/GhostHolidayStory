// Fill out your copyright notice in the Description page of Project Settings.

#include "../../../Public/UserData/Story/Story.h"
#include "LogHelper.h"

void UStory::SetStoryPath(FString storyPath)
{
	this->storyPath = storyPath;
	int lastCharIndex = 0;
	storyPath.FindLastChar(TEXT('/'), lastCharIndex);
	directoryName = storyPath.Right(storyPath.Len() - lastCharIndex - 1);
}

FString UStory::GetStoryPath()
{
	return this->storyPath;
}

FString UStory::GetDirectoryName()
{
	return directoryName;
}

void UStory::LoadInfo()
{
	if (storyPath.IsEmpty())
	{
		LogErrorDetail(TEXT("在读取故事信息前，请先设置故事路径。"));
		return;
	}
	storyInfo = NewObject<UStoryInfo>(this);
	storyInfo->LoadInfo(storyPath+TEXT("/StoryInfo.xml"));
}

void UStory::LoadStory()
{
	if (storyPath.IsEmpty())
	{
		LogErrorDetail(TEXT("在读取故事前，请先设置故事路径。"));
		return;
	}
	if (storyInfo == nullptr)
	{
		LoadInfo();
	}
}

UStoryInfo* UStory::GetStoryInfo()
{
	return storyInfo;
}
