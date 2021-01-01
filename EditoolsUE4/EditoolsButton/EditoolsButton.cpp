
#include "PrevisUIEditor/EditoolsUE4/EditoolsButton/EditoolsButton.h"

TSharedRef<SButton> EditoolsUE4::EditoolsButton::CreateButton(FOnClicked _eventOnClick, FText _textButton, FText _tooltipTextButton)
{
	return SNew(SButton)
		.OnClicked(_eventOnClick)
		[
			SNew(STextBlock)
			.Text(_textButton)
			.ToolTipText(_tooltipTextButton)
		];
}

TSharedRef<SButton> EditoolsUE4::EditoolsButton::CreateButtonWithColor(FOnClicked _eventOnClick, FText _textButton, FText _tooltipTextButton, FLinearColor _buttonColor, FLinearColor _textColor)
{
	return SNew(SButton)
		.OnClicked(_eventOnClick)
		.ButtonColorAndOpacity(FSlateColor(_buttonColor))
		[
			SNew(STextBlock)
			.Text(_textButton)
			.ToolTipText(_tooltipTextButton)
			.ColorAndOpacity(FSlateColor(_textColor))
		];
}
