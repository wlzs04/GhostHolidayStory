// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/TimelineComponent.h"
#include "MainGameInstance.h"
#include "MainPawn.generated.h"

class AGhostHolidayStoryGameModeBase;
class APlayerCameraManager;
class USoundBase;
class APlayerController;

UCLASS()
class GHOSTHOLIDAYSTORY_API AMainPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMainPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//进入放映室
	void EnterStudio();

	//进入放映室的蓝图事件
	UFUNCTION(BlueprintImplementableEvent)
	void EnterStudio_BPEvent();

	//完成进入放映室
	UFUNCTION(BlueprintCallable)
	void EnterStudio_Finish();

	//修改配置
	void ChangeConfig();

	//修改配置的蓝图事件
	UFUNCTION(BlueprintImplementableEvent)
	void ChangeConfig_BPEvent();

	//完成修改配置
	UFUNCTION(BlueprintCallable)
	void ChangeConfig_Finish();

	//选择故事
	void SelectStory();

	//选择故事的蓝图事件
	UFUNCTION(BlueprintImplementableEvent)
	void SelectStory_BPEvent();

	//完成选择故事
	UFUNCTION(BlueprintCallable)
	void SelectStory_Finish();

	//设置存档
	void SetSave();

	//设置存档的蓝图事件
	UFUNCTION(BlueprintImplementableEvent)
	void SetSave_BPEvent();

	//完成设置存档
	UFUNCTION(BlueprintCallable)
	void SetSave_Finish();

	//退出放映室
	void ExitStudio();

	//退出放映室的蓝图事件
	UFUNCTION(BlueprintImplementableEvent)
	void ExitStudio_BPEvent();

	//完成退出放映室
	UFUNCTION(BlueprintCallable)
	void ExitStudio_Finish();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	APlayerCameraManager* currentCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AGhostHolidayStoryGameModeBase* mainGameMode;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMainGameInstance* mainGameInstance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	APlayerController* mainController;
private:

	//修改玩家输入:在放映室外，等待任意键
	void ChangePlayerInput_Outdoor();

	//修改玩家输入:进入放映室，进行更改设置
	void ChangePlayerInput_ChangeConfig();
};
