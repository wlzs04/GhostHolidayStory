// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoryInfo.h"
#include "Story.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class GHOSTHOLIDAYSTORY_API UStory : public UObject
{
	GENERATED_BODY()

public:
	UStory() :UObject() {}
	~UStory() {}

	//设置故事路径
	void SetStoryPath(FString storyPath);

	//获得故事路径
	UFUNCTION(BlueprintCallable)
	FString GetStoryPath();

	//获得目录名称
	UFUNCTION(BlueprintCallable)
	FString GetDirectoryName();

	//仅加载故事的介绍等信息
	void LoadInfo();

	//加载故事
	void LoadStory();

	//获得故事信息
	UFUNCTION(BlueprintCallable)
	UStoryInfo* GetStoryInfo();
private:
	//故事的绝对路径
	FString storyPath;

	//故事在Story目录下的名称
	FString directoryName;

	//故事信息
	UStoryInfo* storyInfo = nullptr;
};
