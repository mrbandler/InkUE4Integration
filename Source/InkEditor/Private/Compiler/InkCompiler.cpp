// Copyright (c) 2018 fivefingergames.

#include "InkCompiler.h"
#include "InkProcess.h"
#include "Tools/InkEditorUtils.h"
#include "Misc/Paths.h"

DEFINE_LOG_CATEGORY(LogInkCompiler);

#pragma region Public API

void FInkCompiler::CompileInk(TArray<UInkAsset*> inkAssets)
{
    if (CheckInklecateCompiler() == false)
    {
        return;
    }

    for (UInkAsset* inkAsset : inkAssets)
    {
        CompilerInkInternal(inkAsset);
    }
}

void FInkCompiler::CompileInk(UInkAsset * inkAsset)
{
    TArray<UInkAsset*> inkAssets;
    inkAssets.Add(inkAsset);

    CompileInk(inkAssets);
}

#pragma endregion

#pragma region Private API

void FInkCompiler::CompilerInkInternal(UInkAsset* inkAsset)
{
    if(inkAsset == nullptr)
    {
        UE_LOG(LogInkCompiler, Error, TEXT("Tried to compile ink asset, but it was null."));
        return;
    }

    // TODO: Check if already compiled.
    // TODO: Ink master asset and stuff checks here.

    TSharedPtr<FInkProcess> process = MakeShareable(new FInkProcess(inkAsset));
    process->Start();
}

bool FInkCompiler::CheckInklecateCompiler()
{
    bool result = true;

    FString inklecatePath = FInkEditorUtils::GetInklecateFilePath();
    if(inklecatePath.IsEmpty() == true)
    {
        UE_LOG(LogInkCompiler, Error, TEXT("Inklecate (the ink compiler) not found in the Plugins Content. This will prevent compiling of ink story files."));
        result = false;
    }

    return result;
}

#pragma endregion
