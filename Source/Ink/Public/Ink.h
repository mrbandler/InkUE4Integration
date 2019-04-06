// Copyright (c) 2018 fivefingergames.

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"

class FInkModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};