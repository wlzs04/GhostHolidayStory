// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class UPaperSprite;
/**
 * 
 */
class GHOSTHOLIDAYSTORY_API SpriteHelper
{
public:
	SpriteHelper();
	~SpriteHelper();

	static UPaperSprite* LoadSprite(FString dictoryPath, FString spriteName);
};
