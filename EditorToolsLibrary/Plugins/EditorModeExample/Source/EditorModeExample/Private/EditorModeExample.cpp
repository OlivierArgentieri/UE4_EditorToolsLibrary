// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorModeExample.h"
#include "EditorModeExampleEdMode.h"

#define LOCTEXT_NAMESPACE "FEditorModeExampleModule"

void FEditorModeExampleModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FEditorModeExampleEdMode>(FEditorModeExampleEdMode::EM_EditorModeExampleEdModeId, LOCTEXT("EditorModeExampleEdModeName", "EditorModeExampleEdMode"), FSlateIcon(), true);
}

void FEditorModeExampleModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FEditorModeExampleEdMode::EM_EditorModeExampleEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorModeExampleModule, EditorModeExample)