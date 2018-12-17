// Fill out your copyright notice in the Description page of Project Settings.

#include "../../../Public/UserData/Story/Story.h"
#include "LogHelper.h"

void UStory::SetStoryPath(FString storyPath)
{
	this->storyPath = storyPath;
}

void UStory::LoadInfo()
{
	if (storyPath.IsEmpty())
	{
		LogErrorDetail(TEXT("在读取故事信息前，请先设置故事路径。"));
		return;
	}
	storyInfo = NewObject<UStoryInfo>(this);
	storyInfo->LoadInfo(storyPath);
}

void UStory::LoadStory()
{
	if (storyPath.IsEmpty())
	{

		return;
	}
	if (storyInfo == nullptr)
	{
		LoadInfo();
	}
}
