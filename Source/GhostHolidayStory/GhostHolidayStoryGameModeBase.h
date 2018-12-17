// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Array.h"
#include "Map.h"
#include "UserData/Config/CommonConfig.h"

#include "GhostHolidayStoryGameModeBase.generated.h"

class AMainGameState;
class AMainPawn;

USTRUCT(BlueprintType)
struct FTextAndAudio
{
	GENERATED_BODY()

	FTextAndAudio()
	{
		text = TEXT("");
		audio = TEXT("");
	}

	FTextAndAudio(FString textValue, FString audioValue)
	{
		text = textValue;
		audio = audioValue;
	}

	UPROPERTY(BlueprintReadOnly)
	FString text;

	UPROPERTY(BlueprintReadOnly)
	FString audio;
};

USTRUCT(BlueprintType)
struct FTalkGroup
{
	GENERATED_BODY()

	FTalkGroup() {}

	UPROPERTY(BlueprintReadOnly)
	FString imagePath;

	UPROPERTY(BlueprintReadOnly)
	FTextAndAudio talk0;

	UPROPERTY(BlueprintReadOnly)
	FTextAndAudio talk1;
};

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

	//设置配置
	void ChangeConfig();

	//选择故事
	void SelectStory();

	//设置存档
	void SetSave();

	//退出放映室
	void ExitStudio();

	//退出游戏
	void ExitGame();

	//保存配置
	void SaveCommonConfig();

	//通过名称获得actor
	AActor* GetActorByName(FString actorName);
	AActor* GetActorChildByName(AActor* baseActor,FString actorName);

	//初始化声音，由蓝图实现，设置不同类型声音的大小,为保证此方法在加载配置之后调用
	UFUNCTION(BlueprintImplementableEvent)
	void InitSound_BPEvent();

	UFUNCTION(BlueprintCallable)
	FTalkGroup GetRandomGreetingsTalkGroup();

	UFUNCTION(BlueprintCallable)
	FTalkGroup GetRandomClosingsTalkGroup();

	UFUNCTION(BlueprintCallable)
	FString GetCommonPath();

	UFUNCTION(BlueprintCallable)
	FString GetRelativeCommonPath();

	UFUNCTION(BlueprintCallable)
	FString GetStoryPath();

	UFUNCTION(BlueprintCallable)
	FString GetRelativeStoryPath();

	UFUNCTION(BlueprintCallable)
	UCommonConfig* GetCommonConfig();

protected:
	UPROPERTY(EditAnywhere)
	UCommonConfig* commonConfig = nullptr;

private:
	//加载普通配置
	void LoadCommonConfig();

	//读取问候语
	void LoadGreetingsFromXML();

	//读取结束语
	void LoadClosingsFromXML();

	//加载所有故事
	void LoadAllStory();

	AMainGameState* mainGameState;
	AMainPawn* mainPawn;

	FString relativeCommonPath = TEXT("GameContent/Data/Common/");
	FString relativeStoryPath = TEXT("GameContent/Data/Story/");

	TArray<FTalkGroup> greetingsList;
	TArray<FTalkGroup> closingsList;


};
