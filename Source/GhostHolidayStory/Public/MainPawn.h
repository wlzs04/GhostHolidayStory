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

	UFUNCTION(BlueprintImplementableEvent)
	void EnterStudio_BPEvent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	APlayerCameraManager* currentCamera;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AGhostHolidayStoryGameModeBase* mainGameMode;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UMainGameInstance* mainGameInstance;

	//UFUNCTION(BlueprintCallable)
	//USoundBase* LoadAudio(FString audioName);
private:

	//修改玩家输入:在放映室外，等待任意键
	void ChangePlayerInput_Outdoor();

	//修改玩家输入:进入放映室，进行更改设置
	void ChangePlayerInput_ChangeConfig();
	

	void ChangeConfigFinish();
};
