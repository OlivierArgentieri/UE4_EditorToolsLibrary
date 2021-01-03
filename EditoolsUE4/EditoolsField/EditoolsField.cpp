#include "EditoolsField.h"


TSharedRef<SEditableTextBox> EditoolsUE4::EditoolsField::CreateTextBox_Lambda(TFunction<void(const FText&)> _lambdaOnEditedText, TFunction<FText()> _lambdaGetText, FLinearColor _textColor, FLinearColor _backgroundColor)
{
	return SNew(SEditableTextBox)
		.BackgroundColor(FSlateColor(_backgroundColor))
		.OnTextChanged_Lambda(_lambdaOnEditedText)
		.Text_Lambda(std::move(_lambdaGetText))
		.ForegroundColor(FSlateColor(_textColor));
}