// Copyright (c) 2018 fivefingergames.

#pragma once

#include "CoreMinimal.h"
#include "Misc/MonitoredProcess.h"

DECLARE_LOG_CATEGORY_EXTERN(LogInkCompilerProcess, Log, All);

class UInkAsset;

/**
 * 
 */
class FInkProcess
{

public:

	FInkProcess(UInkAsset* InkAsset);
	~FInkProcess();

    void Start();

protected:

    TSharedPtr<FMonitoredProcess> Process;
    UInkAsset* InkAsset;

    void CompilationSuccessfull();
    void CompilationUnsuccessfull();

private:

    void CreateProcess();

    void OnCanceled();
    void OnCompleted(int32 ReturnCode);
    void OnOutput(FString Output);

};
