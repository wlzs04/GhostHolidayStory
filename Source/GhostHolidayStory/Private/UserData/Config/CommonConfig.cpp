// Fill out your copyright notice in the Description page of Project Settings.

#include "../../../Public/UserData/Config/CommonConfig.h"

#include "Runtime/XmlParser/Public/XmlParser.h"
#include "Runtime/XmlParser/Public/FastXml.h" 
#include "XmlParser/Public/XmlFile.h"

UCommonConfig::~UCommonConfig()
{
}

void UCommonConfig::SetTotalVolume(float totalVolume)
{
	this->totalVolume = FMath::Clamp<float>(totalVolume,0,1);
}

float UCommonConfig::GetTotalVolume()
{
	return totalVolume;
}

void UCommonConfig::SetBackVolume(float backVolume)
{
	this->backVolume = FMath::Clamp<float>(backVolume, 0, 1);
}

float UCommonConfig::GetBackVolume()
{
	return backVolume;
}

void UCommonConfig::SetVoiceVolume(float voiceVolume)
{
	this->voiceVolume = FMath::Clamp<float>(voiceVolume, 0, 1);
}

float UCommonConfig::GetVoiceVolume()
{
	return voiceVolume;
}

void UCommonConfig::SetSpecialVolume(float specialVolume)
{
	this->specialVolume = FMath::Clamp<float>(specialVolume, 0, 1);
}

float UCommonConfig::GetSpecialVolume()
{
	return specialVolume;
}

void UCommonConfig::SetEnableInterlude(bool enableInterlude)
{
	this->enableInterlude = enableInterlude;
}

bool UCommonConfig::GetEnableInterlude()
{
	return enableInterlude;
}

void UCommonConfig::SetEndGameAutoExit(bool endGameAutoExit)
{
	this->endGameAutoExit = endGameAutoExit;
}

bool UCommonConfig::GetEndGameAutoExit()
{
	return endGameAutoExit;
}

void UCommonConfig::LoadConfig(FString commonConfigPath)
{
	this->commonConfigPath = commonConfigPath;
	FXmlFile* xmlFile = new FXmlFile(commonConfigPath);
	FXmlNode* rootNode = xmlFile->GetRootNode();

	const TArray<FXmlNode*> nodeList = rootNode->GetChildrenNodes();

	for (FXmlNode* nodeItem : nodeList)
	{
		if(nodeItem->GetTag()==TEXT("Volume"))
		{
			FString totalVolumeString = nodeItem->GetAttribute(TEXT("total"));
			FString backVolumeString = nodeItem->GetAttribute(TEXT("back"));
			FString voiceVolumeString = nodeItem->GetAttribute(TEXT("voice"));
			FString specialVolumeString = nodeItem->GetAttribute(TEXT("special"));

			SetTotalVolume(FCString::Atof(*totalVolumeString));
			SetBackVolume(FCString::Atof(*backVolumeString));
			SetVoiceVolume(FCString::Atof(*voiceVolumeString));
			SetSpecialVolume(FCString::Atof(*specialVolumeString));
		}
		else if(nodeItem->GetTag() == TEXT("Switch"))
		{
			FString enableInterludeString = nodeItem->GetAttribute(TEXT("enableInterlude"));
			FString endGameAutoExitString = nodeItem->GetAttribute(TEXT("endGameAutoExit"));
			
			SetEnableInterlude(FCString::ToBool(*enableInterludeString));
			SetEnableInterlude(FCString::ToBool(*enableInterludeString));
		}
	}
}
