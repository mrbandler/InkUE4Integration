// Copyright (c) 2018 fivefingergames.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InkAsset.generated.h"

/**
 * 
 */
UCLASS()
class INK_API UInkAsset : public UObject
{
	GENERATED_BODY()
	
public:
    UPROPERTY(EditAnywhere, Category = "Ink")
    FText InkSource;

    UPROPERTY(EditAnywhere, Category = "Ink")
        FString InkJson;

    FString TempInkFilePath;
    FString TempJsonInkFilePath;

    FString WriteTempInkFile(FString InklecateDir);
    FString GetTempJsonFilePath();
    void ExtractInkJson();
    void ClearTempFiles();

protected:

    FString m_TempInkFilePath;
    FString m_TempJsonInkFilePath;

private:
    static const FString INK_EXTENSION;
    static const FString JSON_EXTENSION;
	
};
