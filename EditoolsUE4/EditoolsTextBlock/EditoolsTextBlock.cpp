#include "EditoolsTextBlock.h"


TSharedRef<STextBlock> EditoolsUE4::EditoolsTextBlock::CreateTextBlock(FText _text, FText _toolTipText, FLinearColor _textColor)
{
	return SNew(STextBlock)
		.Text(_text)
		.ToolTipText(_toolTipText)
		.ColorAndOpacity(FSlateColor(_textColor));
}


TSharedRef<STextBlock> EditoolsUE4::EditoolsTextBlock::CreateTextBlock_DynamicText(TFunction<FText()> _lambdaText, FText _toolTipText, FLinearColor _textColor)
{
	return SNew(STextBlock)
		.ToolTipText(_toolTipText)
		.Text_Lambda(std::move(_lambdaText))
		.ColorAndOpacity(FSlateColor(_textColor));
}

TSharedRef<STextBlock> EditoolsUE4::EditoolsTextBlock::CreateTextBlock_AllDynamic(TFunction<FText()> _lambdaText, TFunction < FText()> _lambdaToolTipText, TFunction < FSlateColor()> _lambdaTextColor)
{
	return SNew(STextBlock)
		.Text_Lambda(std::move(_lambdaText))
		.ToolTipText_Lambda(std::move(_lambdaToolTipText))
		.ColorAndOpacity_Lambda(std::move(_lambdaTextColor));
}