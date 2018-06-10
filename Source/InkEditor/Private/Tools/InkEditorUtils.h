// Copyright (c) 2018 fivefingergames.

#pragma once

#include "CoreMinimal.h"

class UInkAsset;

/**
 * 
 */
class FInkEditorUtils
{

public:
    static const FString INK_EXTENSION;
    static const FString JSON_EXTENSION;

    static FString const GetInklecateFilePath();
    static FString const GetInklecateDir();

private:    
    static const FString INK_PLUGIN_NAME;
    static const FString INKLECATE;
    static const FString EXE_FILE_EXTENSION;


};
