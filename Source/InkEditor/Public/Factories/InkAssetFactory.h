// Copyright (c) 2018 fivefingergames.

#pragma once

#include "Factories/Factory.h"
#include "InkAssetFactory.generated.h"

UCLASS()
class INKEDITOR_API UInkAssetFactory : public UFactory
{
	GENERATED_BODY()
	
public:
    UInkAssetFactory();

    virtual UObject* FactoryCreateFile(UClass* InClass, 
                                       UObject* InParent, 
                                       FName InName, 
                                       EObjectFlags Flags, 
                                       const FString& Filename, 
                                       const TCHAR* Parms, 
                                       FFeedbackContext* Warn, 
                                       bool& bOutOperationCanceled) override;

};