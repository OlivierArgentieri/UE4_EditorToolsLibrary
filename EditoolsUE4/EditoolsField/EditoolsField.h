#pragma once

#include "CoreMinimal.h"

namespace EditoolsUE4
{
	
	class EditoolsField
	{
	public:

		/// <summary>
		/// CreateTextBox create TextBox with callback. usage : TBaseDelegate<FText>.CreateRaw(this,...)
		/// </summary>
		/// <param name="_onEditedText"></param>
		/// <param name="_getText"></param>
		/// <param name="_textColor"></param>
		/// <param name="_backgroundColor"></param>
		/// <returns></returns>
		static TSharedRef<SEditableTextBox> CreateTextBox(FOnTextChanged _onEditedText, TBaseDelegate<FText> _getText, FLinearColor _textColor = FLinearColor::Black, FLinearColor _backgroundColor = FLinearColor::White);

		
		/// <summary>
		/// Create TextBox with getter and edit event has lambda event
		/// </summary>
		/// <param name="_lambdaOnTextChanged"></param>
		/// <param name="_lambdaGetText"></param>
		/// <param name="_textColor"></param>
		/// <param name="_backgroundColor"></param>
		/// <returns></returns>
		static TSharedRef<SEditableTextBox> CreateTextBox_Lambda(TFunction<void(const FText&)> _lambdaOnTextChanged, TFunction<FText()> _lambdaGetText, FLinearColor _textColor = FLinearColor::Black, FLinearColor _backgroundColor= FLinearColor::White);

		/// <summary>
		/// Create TextBox with all params has lambda event
		/// </summary>
		/// <param name="_lambdaOnTextChanged"></param>
		/// <param name="_lambdaGetText"></param>
		/// <param name="_lambdaTextColor"></param>
		/// <param name="_lambdaBackgroundColor"></param>
		/// <returns></returns>
		static TSharedRef<SEditableTextBox> CreateTextBox_AllDynamic(TFunction<void(const FText&)> _lambdaOnTextChanged, TFunction<FText()> _lambdaGetText, TFunction<FSlateColor()> _lambdaTextColor, TFunction<FSlateColor()> _lambdaBackgroundColor);

	};

	
	

}
