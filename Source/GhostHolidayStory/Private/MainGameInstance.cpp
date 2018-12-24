// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameInstance.h"
#include "Helper/AudioHelper.h"
#include "Helper/SpriteHelper.h"

USoundBase* UMainGameInstance::LoadSound(FString dictoryPath, FString audioName)
{
	return AudioHelper::LoadSound(dictoryPath, audioName);
}

UPaperSprite* UMainGameInstance::LoadSprite(FString dictoryPath, FString spriteName)
{
	return SpriteHelper::LoadSprite(dictoryPath, spriteName);
}
