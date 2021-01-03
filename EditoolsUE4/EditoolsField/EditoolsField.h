#pragma once

#include "CoreMinimal.h"

namespace EditoolsUE4
{
	
	class EditoolsField
	{
	public:

		/// <summary>
		/// Create text box with lambda event
		/// </summary>
		/// <param name="_lambdaOnEditedText"></param>
		/// <param name="_lambdaGetText"></param>
		/// <param name="_textColor"></param>
		/// <param name="_backgroundColor"></param>
		/// <returns></returns>
		static TSharedRef<SEditableTextBox> CreateTextBox_Lambda(TFunction<void(const FText&)> _lambdaOnEditedText, TFunction<FText()> _lambdaGetText, FLinearColor _textColor = FLinearColor::Black, FLinearColor _backgroundColor= FLinearColor::White);

	};

	
	

}
