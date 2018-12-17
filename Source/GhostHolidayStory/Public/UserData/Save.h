// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectMacros.h"
#include "NoExportTypes.h"
#include "Save.generated.h"
/**
 * 
 */
UCLASS(BlueprintType)
class GHOSTHOLIDAYSTORY_API USave :public UObject
{
	GENERATED_BODY()

public:
	USave() :UObject() {};
	~USave() {};

	//加载存档
	void LoadSave(FString savePath);
	//保存存档
	void SaveSave(); 

protected:
	FString savePath;

	//创建时间
	UPROPERTY(EditAnywhere)
	FDateTime createTime;

	//最后一次保存时间
	UPROPERTY(EditAnywhere)
	FDateTime lastSaveTime;

	//游戏时间，秒
	UPROPERTY(EditAnywhere)
	int playTime;

	//当前章
	UPROPERTY(EditAnywhere)
	int chapterIndex;

	//当前节
	UPROPERTY(EditAnywhere)
	int sectionIndex;

	//主角团
	TArray<int> starringList;

	//已经完成的章节
	TMap<int,int> haveFinishChapterAndSectionMap;
	
	//需要在登录游戏后执行的指令列表
	TArray<int> needExecuteOnLoadActionList;
	
	//已获得的物品
	TMap<int, int> objectItemMap;
};
