// Copyright (c) 2018 fivefingergames.

#include "InkEditorUtils.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "Interfaces/IPluginManager.h"
#include "InkAsset.h"

const FString FInkEditorUtils::INK_EXTENSION = TEXT("ink");
const FString FInkEditorUtils::JSON_EXTENSION = TEXT("json");

const FString FInkEditorUtils::INK_PLUGIN_NAME = TEXT("inkUE4Integration");
const FString FInkEditorUtils::INKLECATE = TEXT("inklecate");
const FString FInkEditorUtils::EXE_FILE_EXTENSION = TEXT(".exe");

#pragma region Public API

FString const FInkEditorUtils::GetInklecateFilePath()
{
    FString result = GetInklecateDir();
    if(result.IsEmpty() == true)
    {
        return result;
    }

    result = FPaths::Combine(result, FInkEditorUtils::INKLECATE);
    result = FPaths::SetExtension(result, FInkEditorUtils::EXE_FILE_EXTENSION);
    return result;
}

#pragma endregion

#pragma region Private API

FString const FInkEditorUtils::GetInklecateDir()
{
    FString result = "";

    TSharedPtr<IPlugin> plugin = IPluginManager::Get().FindPlugin(FInkEditorUtils::INK_PLUGIN_NAME);
    if(plugin.IsValid() == true)
    {
        FString contentPath = plugin->GetContentDir();
        result = FPaths::Combine(contentPath, FInkEditorUtils::INKLECATE);
    }

    return result;
}

#pragma endregion
