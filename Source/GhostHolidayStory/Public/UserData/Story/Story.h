// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoryInfo.h"
#include "Story.generated.h"

/**
 * 
 */
UCLASS()
class GHOSTHOLIDAYSTORY_API UStory : public UObject
{
	GENERATED_BODY()

public:
	UStory() :UObject() {}
	~UStory() {}

	//设置故事路径
	void SetStoryPath(FString storyPath);

	//仅加载故事的介绍等信息
	void LoadInfo();

	//加载故事
	void LoadStory();
private:
	FString storyPath;

	//故事信息
	UStoryInfo* storyInfo = nullptr;
};
