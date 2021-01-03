#include "EditoolsField.h"


TSharedRef<SEditableTextBox> EditoolsUE4::EditoolsField::CreateTextBox(FOnTextChanged _onEditedText, TBaseDelegate<FText> _getText, FLinearColor _textColor, FLinearColor _backgroundColor)
{
	return SNew(SEditableTextBox)
		.BackgroundColor(FSlateColor(_backgroundColor))
		.OnTextChanged(_onEditedText)
		.Text(_getText.Execute())
		.ForegroundColor(FSlateColor(_textColor));
}

TSharedRef<SEditableTextBox> EditoolsUE4::EditoolsField::CreateTextBox_Lambda(TFunction<void(const FText&)> _lambdaOnTextChanged, TFunction<FText()> _lambdaGetText, FLinearColor _textColor, FLinearColor _backgroundColor)
{
	return SNew(SEditableTextBox)
		.BackgroundColor(FSlateColor(_backgroundColor))
		.OnTextChanged_Lambda(_lambdaOnTextChanged)
		.Text_Lambda(std::move(_lambdaGetText))
		.ForegroundColor(FSlateColor(_textColor));
}

TSharedRef<SEditableTextBox> EditoolsUE4::EditoolsField::CreateTextBox_AllDynamic(TFunction<void(const FText&)> _lambdaOnTextChanged, TFunction<FText()> _lambdaGetText, TFunction<FSlateColor()> _lambdaTextColor, TFunction<FSlateColor()> _lambdaBackgroundColor)
{
	return SNew(SEditableTextBox)
		.BackgroundColor_Lambda(std::move(_lambdaBackgroundColor))
		.OnTextChanged_Lambda(_lambdaOnTextChanged)
		.Text_Lambda(std::move(_lambdaGetText))
		.ForegroundColor_Lambda(std::move(_lambdaTextColor));
}
