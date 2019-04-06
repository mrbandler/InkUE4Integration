// Copyright (c) 2018 fivefingergames.

#include "InkAssetFactory.h"
#include "InkEditor.h"
#include "InkAsset.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Compiler/InkCompiler.h"

DEFINE_LOG_CATEGORY_STATIC(LogInkFactory, Log, All);

UInkAssetFactory::UInkAssetFactory()
{
    bCreateNew = false;
    bText = true;
    bEditorImport = true;
    Formats.Add(TEXT("ink;Ink Story"));
    SupportedClass = UInkAsset::StaticClass();
}

UObject * UInkAssetFactory::FactoryCreateFile(UClass* InClass, 
                                              UObject* InParent, 
                                              FName InName, 
                                              EObjectFlags Flags, 
                                              const FString & Filename, 
                                              const TCHAR* Parms, 
                                              FFeedbackContext* Warn, 
                                              bool &bOutOperationCanceled)
{
    UInkAsset* inkAsset = nullptr;
    FString inkSource;
    if(FFileHelper::LoadFileToString(inkSource, *Filename) == true)
    {
        inkAsset = NewObject<UInkAsset>(InParent, InClass, InName, Flags);
        inkAsset->InkSource = FText::FromString(inkSource);

        // TODO: Compile asset here.
        FInkCompiler::CompileInk(inkAsset);
    }

    bOutOperationCanceled = false;

    return inkAsset;
}