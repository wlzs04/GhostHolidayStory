// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MainGameState.generated.h"

UENUM(BlueprintType)
enum class MainGameStateEnum :uint8
{
	Outdoor UMETA(DisplayName = "放映室外"),
	ChangeConfig UMETA(DisplayName = "修改配置"),
	SelectStory UMETA(DisplayName = "选择故事"),
	SetSave UMETA(DisplayName = "设置存档"),
	Action UMETA(DisplayName = "开始"),
	Exit UMETA(DisplayName = "退出"),
};

/**
 * 
 */
UCLASS()
class GHOSTHOLIDAYSTORY_API AMainGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	AMainGameState();

	UFUNCTION(BlueprintCallable)
	void SetMainGameStateEnum(MainGameStateEnum e);

	UFUNCTION(BlueprintCallable)
	MainGameStateEnum GetMainGameStateEnum();

private:
	UPROPERTY(EditDefaultsOnly)
	MainGameStateEnum mainGameStateEnum;
};
