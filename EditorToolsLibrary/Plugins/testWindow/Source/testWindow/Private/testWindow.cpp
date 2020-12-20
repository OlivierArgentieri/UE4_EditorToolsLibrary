// Copyright Epic Games, Inc. All Rights Reserved.

#include "testWindow.h"
#include "testWindowStyle.h"
#include "testWindowCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName testWindowTabName("testWindow");

#define LOCTEXT_NAMESPACE "FtestWindowModule"

void FtestWindowModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FtestWindowStyle::Initialize();
	FtestWindowStyle::ReloadTextures();

	FtestWindowCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FtestWindowCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FtestWindowModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FtestWindowModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(testWindowTabName, FOnSpawnTab::CreateRaw(this, &FtestWindowModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FtestWindowTabTitle", "testWindow"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FtestWindowModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FtestWindowStyle::Shutdown();

	FtestWindowCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(testWindowTabName);
}

TSharedRef<SDockTab> FtestWindowModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FtestWindowModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("testWindow.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FtestWindowModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(testWindowTabName);
}

void FtestWindowModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FtestWindowCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FtestWindowCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FtestWindowModule, testWindow)