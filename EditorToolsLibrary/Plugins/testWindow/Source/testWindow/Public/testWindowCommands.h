// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "testWindowStyle.h"

class FtestWindowCommands : public TCommands<FtestWindowCommands>
{
public:

	FtestWindowCommands()
		: TCommands<FtestWindowCommands>(TEXT("testWindow"), NSLOCTEXT("Contexts", "testWindow", "testWindow Plugin"), NAME_None, FtestWindowStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};