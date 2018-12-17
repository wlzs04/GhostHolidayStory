// Fill out your copyright notice in the Description page of Project Settings.

#include "../../../Public/UserData/Story/StoryInfo.h"

#include "Runtime/XmlParser/Public/XmlParser.h"
#include "Runtime/XmlParser/Public/FastXml.h" 
#include "XmlParser/Public/XmlFile.h"
#include "LogHelper.h"

void UStoryInfo::LoadInfo(FString infoPath)
{
	FXmlFile* xmlFile = new FXmlFile(infoPath);
	if (!xmlFile->IsValid())
	{
		LogError(TEXT("StoryInfo文件加载失败：") + infoPath);
		return;
	}

	FXmlNode* rootNode = xmlFile->GetRootNode();

	//加载基础属性
	{
		author = rootNode->GetAttribute(TEXT("author"));
	}

	const TArray<FXmlNode*> nodeList = rootNode->GetChildrenNodes();

	for (FXmlNode* nodeItem : nodeList)
	{
		//存档相关
		if (nodeItem->GetTag() == TEXT("Save"))
		{
			FString maxSaveNumberString = nodeItem->GetAttribute(TEXT("maxSaveNumber"));
			maxSaveNumber = FCString::Atoi(*maxSaveNumberString);

			FString lastSaveIndexString = nodeItem->GetAttribute(TEXT("lastSaveIndex"));
			lastSaveIndex = FCString::Atoi(*lastSaveIndexString);
		}
		//预览相关
		else if (nodeItem->GetTag() == TEXT("Preview"))
		{
			description = nodeItem->GetAttribute(TEXT("description"));
			imagePath = nodeItem->GetAttribute(TEXT("imagePath"));
		}
		else
		{
			LogError(TEXT("StoryInfo文件加载到未知节点：") + infoPath + TEXT("：") + nodeItem->GetTag());
		}
	}

	xmlFile->Clear();
	delete xmlFile;

	LogNormal(TEXT("StoryInfo文件：") + infoPath + TEXT("加载完成！"));
}

FString UStoryInfo::GetAuthor()
{
	return author;
}

int UStoryInfo::GetMaxSaveNumber()
{
	return maxSaveNumber;
}

int UStoryInfo::GetLastSaveIndex()
{
	return lastSaveIndex;
}

FString UStoryInfo::GetDescription()
{
	return description;
}

FString UStoryInfo::GetImagePath()
{
	return imagePath;
}