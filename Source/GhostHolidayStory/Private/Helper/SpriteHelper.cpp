// Fill out your copyright notice in the Description page of Project Settings.

#include "SpriteHelper.h"
#include "../Plugins/2D/Paper2D/Source/Paper2D/Classes/PaperSprite.h"
#include "LogHelper.h"

SpriteHelper::SpriteHelper()
{
}

SpriteHelper::~SpriteHelper()
{
}

UPaperSprite* SpriteHelper::LoadSprite(FString dictoryPath, FString spriteName)
{
	//因为在配置文件中spriteName属性可能包含路径，所以先将真实名称截取出来。
	int lastCharIndex = 0;
	spriteName.FindLastChar(TEXT('/'), lastCharIndex);
	FString realSpriteName = spriteName.Right(spriteName.Len() - lastCharIndex - 1);

	FString spritePath = TEXT("/Game/" + dictoryPath + spriteName);
	UPaperSprite* sprite = LoadObject<UPaperSprite>(nullptr, *spritePath);
	if (!sprite)
	{
		LogErrorDetail(spritePath + TEXT("加载失败！"));
	}
	return sprite;
}
