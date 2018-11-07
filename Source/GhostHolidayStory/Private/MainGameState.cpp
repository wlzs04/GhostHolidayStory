// Fill out your copyright notice in the Description page of Project Settings.

#include "../public/MainGameState.h"

AMainGameState::AMainGameState()
{
	mainGameStateEnum = MainGameStateEnum::Outdoor;
}

void AMainGameState::SetMainGameStateEnum(MainGameStateEnum e)
{
	mainGameStateEnum = e;
}

MainGameStateEnum AMainGameState::GetMainGameStateEnum()
{
	return mainGameStateEnum;
}
