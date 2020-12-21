#include "EditoolsUE4.h"

TSharedRef<SButton> EditoolsUE4::EditoolsButton::CreateButton(FOnClicked _eventOnClick, const char* _textButton, const char* _tooltipTextButton)
{
	return SNew(SButton)
	.OnClicked(_eventOnClick)
	[
		SNew(STextBlock)
		.Text(FText::FromString(_textButton))
		.ToolTipText(FText::FromString(_textButton))
	];
}
