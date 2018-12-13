// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectMacros.h"
#include "NoExportTypes.h"
#include "CommonConfig.generated.h"
/**
 * 
 */
UCLASS(BlueprintType)
class GHOSTHOLIDAYSTORY_API UCommonConfig:public UObject
{
	GENERATED_BODY()

public:
	UCommonConfig() :UObject() {};
	~UCommonConfig();

	void LoadConfig(FString commonConfigPath);
	void SaveConfig();

	//主开关
	UFUNCTION(BlueprintSetter)
	void SetMainSwitch(bool mainSwitch);
	UFUNCTION(BlueprintGetter)
	bool GetMainSwitch();

	//总音量
	UFUNCTION(BlueprintSetter)
	void SetTotalVolume(float totalVolume);
	UFUNCTION(BlueprintGetter)
	float GetTotalVolume();

	//背景音量
	UFUNCTION(BlueprintSetter)
	void SetBackVolume(float backVolume);
	UFUNCTION(BlueprintGetter)
	float GetBackVolume();

	//语言音量
	UFUNCTION(BlueprintSetter)
	void SetVoiceVolume(float voiceVolume);
	UFUNCTION(BlueprintGetter)
	float GetVoiceVolume();

	//特殊音量
	UFUNCTION(BlueprintSetter)
	void SetSpecialVolume(float specialVolume);
	UFUNCTION(BlueprintGetter)
	float GetSpecialVolume();

	//过场动画
	UFUNCTION(BlueprintCallable)
	void SetEnableInterlude(bool enableInterlude);
	UFUNCTION(BlueprintCallable)
	bool GetEnableInterlude();

	//游戏结束后自动退出
	UFUNCTION(BlueprintCallable)
	void SetEndGameAutoExit(bool endGameAutoExit);
	UFUNCTION(BlueprintCallable)
	bool GetEndGameAutoExit();
protected:
	FString commonConfigPath;

	//主开关
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool mainSwitch = false;

	//总音量
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float totalVolume=1;

	//背景音量
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	float backVolume = 1;

	//语言音量
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float voiceVolume = 1;

	//特殊音量
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float specialVolume = 1;

	//过场动画
	UPROPERTY(EditAnywhere)
	bool enableInterlude = true;

	//游戏结束后自动退出
	UPROPERTY(EditAnywhere)
	bool endGameAutoExit=true;
};
