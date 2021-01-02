
#include "PrevisUIEditor/EditoolsUE4/EditoolsButton/EditoolsButton.h"



TSharedRef<SButton> EditoolsUE4::EditoolsButton::CreateButton(FOnClicked _eventOnClick, FText _textButton, FText _tooltipTextButton, FLinearColor _buttonColor, FLinearColor _textColor)
{
	return SNew(SButton)
		.OnClicked(_eventOnClick)
		.ToolTipText(_tooltipTextButton)
		.ButtonColorAndOpacity(FSlateColor(_buttonColor))
		[
			SNew(STextBlock)
			.Text(_textButton)
			
			.ColorAndOpacity(FSlateColor(_textColor))
		];
}

TSharedRef<SButton> EditoolsUE4::EditoolsButton::CreateButton_Lambda(TFunction<FReply()> _lambdaEventOnClick, FText _textButton, FText _tooltipTextButton, FLinearColor _buttonColor, FLinearColor _textColor)
{
	return SNew(SButton)
		.OnClicked_Lambda(_lambdaEventOnClick)
		.ToolTipText(_tooltipTextButton)
		.ButtonColorAndOpacity(FSlateColor(_buttonColor))
		[
			SNew(STextBlock)
			.Text(_textButton)
		.ToolTipText(_tooltipTextButton)
		.ColorAndOpacity(FSlateColor(_textColor))
		];
}



TSharedRef<SButton> EditoolsUE4::EditoolsButton::CreateButton_DynamicText(FOnClicked _eventOnClick, TFunction<FText()> _lambdaTextButton, TFunction<FText()>  _lambdaTooltipTextButton, FLinearColor _buttonColor, FLinearColor _textColor)
{
	return SNew(SButton)
		.OnClicked(_eventOnClick)
		.ToolTipText_Lambda(std::move(_lambdaTooltipTextButton))
		.ButtonColorAndOpacity(FSlateColor(_buttonColor))
		[
			SNew(STextBlock)
			.Text_Lambda(std::move(_lambdaTextButton))
			.ColorAndOpacity(FSlateColor(_textColor))
		];
}

TSharedRef<SButton> EditoolsUE4::EditoolsButton::CreateButton_AllDynamic(TFunction<FReply()> _lambdaEventOnClick, TFunction<FText()> _lambdaTextButton, TFunction<FText()>  _lambdaTooltipTextButton, TFunction<FSlateColor()> _LambdaButtonColor, TFunction<FSlateColor()> _lambdaTextColor)
{
	return SNew(SButton)
		.OnClicked_Lambda(_lambdaEventOnClick)
		.ToolTipText_Lambda(std::move(_lambdaTooltipTextButton))
		.ButtonColorAndOpacity_Lambda(std::move(_LambdaButtonColor))
		[
			SNew(STextBlock)
			.Text_Lambda(std::move(_lambdaTextButton))
			.ColorAndOpacity_Lambda(std::move(_lambdaTextColor))
		];
}