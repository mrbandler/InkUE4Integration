// Copyright (c) 2018 fivefingergames.

#include "InkProcess.h"
#include "InkAsset.h"
#include "Tools/InkEditorUtils.h"
#include "Misc/MonitoredProcess.h"

DEFINE_LOG_CATEGORY(LogInkCompilerProcess);

#pragma region Public API

FInkProcess::FInkProcess(UInkAsset* InkAsset)
{
    this->InkAsset = InkAsset;

    CreateProcess();
}

FInkProcess::~FInkProcess()
{
    Process->Cancel(true);
}

void FInkProcess::Start()
{
    Process->SetSleepInterval(1.0f);
;   if(Process->Launch() == false)
    {
        FString message = TEXT("Launching inklecate failed. Compilation of '" + InkAsset->GetName() + "' could not start.");
        UE_LOG(LogInkCompilerProcess, Fatal, TEXT("%s"), *message);
    }
}

#pragma endregion

#pragma region Protected API

void FInkProcess::CompilationSuccessfull()
{
    InkAsset->ExtractInkJson();
    InkAsset->ClearTempFiles();
}

void FInkProcess::CompilationUnsuccessfull()
{
    InkAsset->ClearTempFiles();
}

#pragma endregion

#pragma region Private API

void FInkProcess::CreateProcess()
{
    FString inklecateDir = FInkEditorUtils::GetInklecateDir();
    
    FString tempInkFilePath = InkAsset->WriteTempInkFile(inklecateDir);
    FString tempJsonFilePath = InkAsset->GetTempJsonFilePath();

    FString inklecatePath = FInkEditorUtils::GetInklecateFilePath();
    FString inkArguments = "-c -v -o " + tempJsonFilePath + " " + tempInkFilePath;

    Process = MakeShareable(new FMonitoredProcess(inklecatePath, inkArguments, true));

    Process->OnCanceled().BindRaw(this, &FInkProcess::OnCanceled);
    Process->OnCompleted().BindRaw(this, &FInkProcess::OnCompleted);
    Process->OnOutput().BindRaw(this, &FInkProcess::OnOutput);
}

void FInkProcess::OnCanceled()
{
    // Strange thing, sometimes the OnCanceled is called instead of the OnCompleted.
    // Compilation could none the less be successfully, so we check the return code here and continue like nothing happened...
    int32 returnCode = Process->GetReturnCode();
    if(returnCode == 0)
    {
        FString message = TEXT("Compilation of '" + InkAsset->GetName() + "' finished successfully.");
        UE_LOG(LogInkCompilerProcess, All, TEXT("%s"), *message);

        CompilationSuccessfull();
    }
    else
    {
        FString message = TEXT("The inklecate process has been canceled. Compilation of '" + InkAsset->GetName() + "' did not finish.");
        UE_LOG(LogInkCompilerProcess, Warning, TEXT("%s"), *message);

        CompilationUnsuccessfull();
    }
}

void FInkProcess::OnCompleted(int32 ReturnCode)
{
    if(ReturnCode == 0)
    {
        FString message = TEXT("Compilation of '" + InkAsset->GetName() + "' finished successfully.");
        UE_LOG(LogInkCompilerProcess, All, TEXT("%s"), *message);

        CompilationSuccessfull();
    }
    else
    {
        FString message = TEXT("Compilation of '" + InkAsset->GetName() + "' finished faulty. Return code: " + FString::FromInt(ReturnCode));
        UE_LOG(LogInkCompilerProcess, Warning, TEXT("%s"), *message);

        CompilationUnsuccessfull();
    }
}

void FInkProcess::OnOutput(FString Output)
{
    FString message = TEXT("Compilation of '" + InkAsset->GetName() + "' output: " + Output);
    UE_LOG(LogInkCompilerProcess, All, TEXT("%s"), *message);
}

#pragma endregion
