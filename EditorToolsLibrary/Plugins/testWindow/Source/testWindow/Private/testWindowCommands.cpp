// Copyright Epic Games, Inc. All Rights Reserved.

#include "testWindowCommands.h"

#define LOCTEXT_NAMESPACE "FtestWindowModule"

void FtestWindowCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "testWindow", "Bring up testWindow window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
