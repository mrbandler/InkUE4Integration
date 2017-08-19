// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "ink_UE4_integration.h"

#define LOCTEXT_NAMESPACE "Fink_UE4_integrationModule"

void Fink_UE4_integrationModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void Fink_UE4_integrationModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(Fink_UE4_integrationModule, ink_UE4_integration)