// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StoryInfo.generated.h"

/**
 * 
 */
UCLASS()
class GHOSTHOLIDAYSTORY_API UStoryInfo : public UObject
{
	GENERATED_BODY()
	
public:
	//加载信息
	void LoadInfo(FString infoPath);
	
	//获得作者
	UFUNCTION(BlueprintCallable)
	FString GetAuthor();

	//获得最大存档数量
	UFUNCTION(BlueprintCallable)
	int GetMaxSaveNumber();

	//获得上次存档索引
	UFUNCTION(BlueprintCallable)
	int GetLastSaveIndex();

	//获得描述
	UFUNCTION(BlueprintCallable)
	FString GetDescription();

	//获得图片路径
	UFUNCTION(BlueprintCallable)
	FString GetImagePath();

private:
	//作者
	FString author;

	//最大存档数量
	int maxSaveNumber = 10;

	//上次存档索引
	int lastSaveIndex = 0;

	//描述
	FString description;

	//图片路径
	FString imagePath;
};
