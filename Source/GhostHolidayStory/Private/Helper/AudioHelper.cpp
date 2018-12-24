// Fill out your copyright notice in the Description page of Project Settings.

#include "AudioHelper.h"
#include "UObjectGlobals.h"
#include "Sound/SoundBase.h"
#include "Engine/Engine.h"
#include "LogHelper.h"
#include "FileManager.h"
#include "Story/StoryInfo.h"

AudioHelper::AudioHelper()
{
}

AudioHelper::~AudioHelper()
{
}

USoundBase* AudioHelper::LoadSound(FString dictoryPath, FString audioName)
{
	//因为在配置文件中audioName属性可能包含路径，所以先将真实名称截取出来。
	int lastCharIndex = 0;
	audioName.FindLastChar(TEXT('/'), lastCharIndex);
	FString realAudioName = audioName.Right(audioName.Len()-lastCharIndex-1);

	FString audioPath = TEXT("SoundWave'/Game/"+ dictoryPath + audioName + "." + realAudioName + "'");
	USoundBase* sound = LoadObject<USoundBase>(nullptr, *audioPath);
	if (!sound)
	{
		LogErrorDetail(audioPath + TEXT("加载失败！"));
	}
	return sound;
}
