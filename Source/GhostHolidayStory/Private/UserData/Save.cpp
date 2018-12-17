// Fill out your copyright notice in the Description page of Project Settings.

#include "Save.h"

#include "Runtime/XmlParser/Public/XmlParser.h"
#include "Runtime/XmlParser/Public/FastXml.h" 
#include "XmlParser/Public/XmlFile.h"
#include "LogHelper.h"

void USave::LoadSave(FString savePath)
{
	this->savePath = savePath;
	FXmlFile* xmlFile = new FXmlFile(savePath);
	if (!xmlFile->IsValid())
	{
		LogError(TEXT("Save文件加载失败：") + savePath);
		return;
	}

	FXmlNode* rootNode = xmlFile->GetRootNode();

	//加载基础属性
	{
		FDateTime::Parse(rootNode->GetAttribute(TEXT("createTime")), createTime);
		FDateTime::Parse(rootNode->GetAttribute(TEXT("lastSaveTime")), lastSaveTime);
		FString playTimeString = rootNode->GetAttribute(TEXT("playTime"));
		playTime = FCString::Atoi(*playTimeString);
		FString chapterIndexString = rootNode->GetAttribute(TEXT("chapterIndex"));
		chapterIndex = FCString::Atoi(*chapterIndexString);
		FString sectionIndextring = rootNode->GetAttribute(TEXT("chapterIndex"));
		sectionIndex = FCString::Atoi(*sectionIndextring);
	}

	const TArray<FXmlNode*> nodeList = rootNode->GetChildrenNodes();

	for (FXmlNode* nodeItem : nodeList)
	{
		//加载主角团
		if (nodeItem->GetTag() == TEXT("Starring"))
		{

		}
		//加载已经完成的章节
		else if (nodeItem->GetTag() == TEXT("HaveFinishChapterAndSection"))
		{

		}
		//加载需要在登录游戏后执行的指令列表
		else if (nodeItem->GetTag() == TEXT("NeedExecuteOnLoadAction"))
		{

		}
		//加载已获得的物品
		else if (nodeItem->GetTag() == TEXT("ObjectItemMap"))
		{

		}
		else
		{
			LogError(TEXT("Save文件加载到未知节点：") + savePath + TEXT("：") + nodeItem->GetTag());
		}
	}

	xmlFile->Clear();
	delete xmlFile;

	LogNormal(TEXT("Save文件：") + savePath + TEXT("加载完成！"));
}

void USave::SaveSave()
{
}
