// Fill out your copyright notice in the Description page of Project Settings.

#include "../public/MainPawn.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "GhostHolidayStoryGameModeBase.h"
#include "Sound/SoundBase.h"
#include "Engine/Engine.h"
#include "FileManager.h"
//#include "Sound/SoundWave.h"
#include "Runtime/Engine/Classes/Sound/SoundWave.h"
#include "FileHelper.h"


// Sets default values
AMainPawn::AMainPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainPawn::BeginPlay()
{
	APawn::BeginPlay();
	mainGameMode =Cast<AGhostHolidayStoryGameModeBase>(GetWorld()->GetAuthGameMode()) ;
	mainGameInstance = Cast<UMainGameInstance>(GetGameInstance());
	ChangePlayerInput_Outdoor();

	currentCamera = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
}

// Called every frame
void AMainPawn::Tick(float DeltaTime)
{
	APawn::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMainPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	APawn::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMainPawn::EnterStudio()
{
	ChangePlayerInput_ChangeConfig();
	EnterStudio_BPEvent();
}

void AMainPawn::ChangePlayerInput_Outdoor()
{
	InputComponent->ClearActionBindings();
	InputComponent->BindAction("AnyKey", IE_Pressed, mainGameMode, &AGhostHolidayStoryGameModeBase::EnterStudio);
}

void AMainPawn::ChangePlayerInput_ChangeConfig()
{
	InputComponent->ClearActionBindings();
	InputComponent->BindAction("Finish", IE_Pressed, this, &AMainPawn::ChangeConfigFinish);
}

void AMainPawn::ChangeConfigFinish()
{

}

