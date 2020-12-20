// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorModeExampleEdMode.h"
#include "EditorModeExampleEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

const FEditorModeID FEditorModeExampleEdMode::EM_EditorModeExampleEdModeId = TEXT("EM_EditorModeExampleEdMode");

FEditorModeExampleEdMode::FEditorModeExampleEdMode()
{

}

FEditorModeExampleEdMode::~FEditorModeExampleEdMode()
{

}

void FEditorModeExampleEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FEditorModeExampleEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FEditorModeExampleEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FEditorModeExampleEdMode::UsesToolkits() const
{
	return true;
}




