// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectMacros.h"
#include "NoExportTypes.h"
#include "CommonConfig.generated.h"
/**
 * 
 */
UCLASS()
class GHOSTHOLIDAYSTORY_API UCommonConfig:public UObject
{
	GENERATED_BODY()

public:
	UCommonConfig() :UObject() {};
	~UCommonConfig();

	void LoadConfig(FString commonConfigPath);

	//总音量
	UFUNCTION(BlueprintCallable)
	void SetTotalVolume(float totalVolume);
	UFUNCTION(BlueprintCallable)
	float GetTotalVolume();

	//背景音量
	UFUNCTION(BlueprintCallable)
	void SetBackVolume(float backVolume);
	UFUNCTION(BlueprintCallable)
	float GetBackVolume();

	//语言音量
	UFUNCTION(BlueprintCallable)
	void SetVoiceVolume(float voiceVolume);
	UFUNCTION(BlueprintCallable)
	float GetVoiceVolume();

	//特殊音量
	UFUNCTION(BlueprintCallable)
	void SetSpecialVolume(float specialVolume);
	UFUNCTION(BlueprintCallable)
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
private:
	FString commonConfigPath;

	//总音量
	UPROPERTY(EditDefaultsOnly)
	float totalVolume=1;

	//背景音量
	UPROPERTY(EditDefaultsOnly)
	float backVolume = 1;

	//语言音量
	UPROPERTY(EditDefaultsOnly)
	float voiceVolume = 1;

	//特殊音量
	UPROPERTY(EditDefaultsOnly)
	float specialVolume = 1;

	//过场动画
	UPROPERTY(EditDefaultsOnly)
	bool enableInterlude = true;

	//游戏结束后自动退出
	UPROPERTY(EditDefaultsOnly)
	bool endGameAutoExit=true;
};
