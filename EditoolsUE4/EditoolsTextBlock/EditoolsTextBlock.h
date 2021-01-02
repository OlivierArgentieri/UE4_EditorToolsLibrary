#pragma once

#include "CoreMinimal.h"

namespace EditoolsUE4
{
	class EditoolsTextBlock
	{
		public:

			/// <summary>
			/// Create Basic TextBlock
			/// </summary>
			/// <param name="_text"></param>
			/// <param name="_toolTipText"></param>
			/// <param name="_textColor"></param>
			/// <returns></returns>
			static TSharedRef<STextBlock> CreateTextBlock(FText _text, FText _toolTipText, FLinearColor _textColor = FLinearColor::Black);


			/// <summary>
			/// Create TextBlock with dynamic text (lambda expression)
			/// </summary>
			/// <param name="_lambdaText"></param>
			/// <param name="_toolTipText"></param>
			/// <param name="_textColor"></param>
			/// <returns>TSharedRef<STextBlock></returns>
			static TSharedRef<STextBlock> CreateTextBlock_DynamicText(TFunction<FText()> _lambdaText, FText _toolTipText, FLinearColor _textColor = FLinearColor::Black);

			/// <summary>
			/// Create TextBlock with all text dynamic (lambda for text and tooltipText)
			/// </summary>
			/// <param name="_lambdaText"></param>
			/// <param name="_lambdaToolTipText"></param>
			/// <param name="_lambdaTextColor"></param>
			/// <returns>TSharedRef<STextBlock></returns>
			static TSharedRef<STextBlock> CreateTextBlock_AllDynamic(TFunction<FText()> _lambdaText, TFunction<FText()> _lambdaToolTipText, TFunction < FSlateColor()> _lambdaTextColor);
	};
}