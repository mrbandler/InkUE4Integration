// Copyright (c) 2018 fivefingergames.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogInkCompiler, Log, All);

// Forward declaration.
class UInkAsset;

/**
 * 
 */
class FInkCompiler
{

public:
    static void CompileInk(TArray<UInkAsset*> inkAssets);
    static void CompileInk(UInkAsset* inkAsset);

private:
    static void CompilerInkInternal(UInkAsset* inkAsset);
    static bool CheckInklecateCompiler();

};
