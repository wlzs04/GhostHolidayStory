// Fill out your copyright notice in the Description page of Project Settings.

#include "../../Public/Helper/LogHelper.h"
#include "FileHelper.h"
#include <iostream>

LogHelper* LogHelper::logHelper = new LogHelper();

LogHelper::LogHelper()
{
	
}

LogHelper::~LogHelper()
{
}

LogHelper* LogHelper::GetInstance()
{
	return logHelper;
}

void LogHelper::Init(FString filePath)
{
	this->filePath = filePath;
	FFileHelper::SaveStringToFile(TEXT(""),*filePath);
}

void LogHelper::SetEnable(bool enable)
{
	this->enable = enable;
}

void LogHelper::Log(FString logLevel, FString content, FString logFile, FString logFunction, int logLine, FString logDate, FString logTime)
{
	if (!enable || filePath.IsEmpty())
	{
		return;
	}
	FString sentence = logLevel;
	sentence.Append(TEXT(" File:"));
	sentence.Append(logFile);
	sentence.Append(TEXT(" Function:"));
	sentence.Append(logFunction);
	sentence.Append(TEXT(" Line:"));
	sentence.Append(FString::FromInt(logLine));
	sentence.Append(TEXT(" Time:"));
	sentence.Append(logDate+ TEXT(" ")+logTime);
	sentence.Append(TEXT(" Content:"));
	sentence.Append(content);
	sentence.Append(TEXT("\n"));

	FFileHelper::SaveStringToFile(sentence, *filePath, FFileHelper::EEncodingOptions::ForceUTF8, &IFileManager::Get(), FILEWRITE_Append);
}

void LogHelper::Log(FString logLevel, FString content)
{
	if (!enable || filePath.IsEmpty())
	{
		return;
	}
	FString sentence = logLevel;
	sentence.Append(TEXT(" Content:"));
	sentence.Append(content);
	sentence.Append(TEXT("\n"));

	FFileHelper::SaveStringToFile(sentence, *filePath, FFileHelper::EEncodingOptions::ForceUTF8, &IFileManager::Get(), FILEWRITE_Append);
}

