// Fill out your copyright notice in the Description page of Project Settings.

#include "AudioHelper.h"
#include "UObjectGlobals.h"
#include "Sound/SoundBase.h"
#include "Engine/Engine.h"

AudioHelper::AudioHelper()
{
}

AudioHelper::~AudioHelper()
{
}

USoundBase* AudioHelper::LoadSound(FString dictoryPath, FString audioName)
{
	FString audioPath = TEXT("SoundWave'/Game/"+ dictoryPath + audioName + "." + audioName + "'");
	USoundBase* sound = LoadObject<USoundBase>(nullptr, *audioPath);
	if (!sound)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, audioPath + TEXT("加载失败！"));
	}
	return sound;
}
