#pragma once

#include "CoreMinimal.h"

class USoundBase;

/**
 * 
 */

class GHOSTHOLIDAYSTORY_API AudioHelper
{
public:
	AudioHelper();
	~AudioHelper();

	static USoundBase* LoadSound(FString dictoryPath,FString audioName);
};
