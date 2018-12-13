// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealString.h"

//日志等级
enum class LogLevel
{
	Normal,//普通
	Warning,//警告
	Error,//错误
};

/**
 * 
 */
class GHOSTHOLIDAYSTORY_API LogHelper
{
public:
	void Init(FString filePath);

	void SetEnable(bool enable);

	static LogHelper* GetInstance();

	void Log(FString logLevel, FString content, FString logFile, FString logFunction, int logLine, FString logDate, FString logTime);
	void Log(FString logLevel, FString content);

private:
	LogHelper();
	~LogHelper();

	FString filePath;
	bool enable = true;

	static LogHelper* logHelper;
};

#define LogNormal(x) LogHelper::GetInstance()->Log(TEXT("Normal:"), x);
#define LogWarning(x) LogHelper::GetInstance()->Log(TEXT("Warning:"), x);
#define LogError(x) LogHelper::GetInstance()->Log(TEXT("Error:"), x);

#define LogNormalDetail(x) LogHelper::GetInstance()->Log(TEXT("Normal:"), x, TEXT(__FILE__),TEXT(__FUNCTION__), __LINE__, TEXT(__DATE__), TEXT(__TIME__));
#define LogWarningDetail(x) LogHelper::GetInstance()->Log(TEXT("Warning:"), x, TEXT(__FILE__),TEXT(__FUNCTION__), __LINE__, TEXT(__DATE__), TEXT(__TIME__));
#define LogErrorDetail(x) LogHelper::GetInstance()->Log(TEXT("Error:"), x, TEXT(__FILE__),TEXT(__FUNCTION__), __LINE__, TEXT(__DATE__), TEXT(__TIME__));
