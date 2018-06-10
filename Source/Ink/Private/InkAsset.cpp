// Copyright (c) 2018 fivefingergames.

#include "InkAsset.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"

const FString UInkAsset::INK_EXTENSION = TEXT("ink");
const FString UInkAsset::JSON_EXTENSION = TEXT("json");

FString UInkAsset::WriteTempInkFile(FString InklecateDir)
{
    m_TempInkFilePath = FPaths::Combine(InklecateDir, GetName());
    m_TempInkFilePath = FPaths::SetExtension(m_TempInkFilePath, UInkAsset::INK_EXTENSION);

    FFileHelper::SaveStringToFile(InkSource.ToString(), *m_TempInkFilePath);
    return m_TempInkFilePath;
}

FString UInkAsset::GetTempJsonFilePath()
{
    m_TempJsonInkFilePath = FPaths::ChangeExtension(m_TempInkFilePath, UInkAsset::JSON_EXTENSION);
    return m_TempJsonInkFilePath;
}

void UInkAsset::ExtractInkJson()
{
    FFileHelper::LoadFileToString(InkJson, *m_TempJsonInkFilePath);
}

void UInkAsset::ClearTempFiles()
{
    IFileManager::Get().Delete(*m_TempInkFilePath, false);
    IFileManager::Get().Delete(*m_TempJsonInkFilePath, false);
}
