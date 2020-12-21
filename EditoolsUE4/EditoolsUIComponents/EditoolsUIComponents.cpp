#include "EditoolsUIComponents.h"


TSharedRef<SButton> EditoolsUE4::EditoolsUIComponents::CreateButton(FOnClicked _eventOnClick, FText _textButton, FText _tooltipTextButton)
{
	return SNew(SButton)
	.OnClicked(_eventOnClick)
	[
		SNew(STextBlock)
		.Text(_textButton)
		.ToolTipText(_tooltipTextButton)
	];
}

TSharedRef<STextBlock> EditoolsUE4::EditoolsUIComponents::CreateTextBlock(FText _text)
{
	return SNew(STextBlock)
	.Text(_text);
}
