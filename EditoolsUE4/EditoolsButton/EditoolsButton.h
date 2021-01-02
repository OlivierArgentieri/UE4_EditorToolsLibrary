#pragma once

#include "CoreMinimal.h"


namespace EditoolsUE4
{
	/// <summary>
	/// Class Button of editoolsUE4
	/// </summary>
	class EditoolsButton
	{
		public:
		/// <summary>
		/// Create Button with basic options
		/// </summary>
		/// <param name="_eventOnClick"></param>
		/// <param name="_textButton"></param>
		/// <param name="_tooltipTextButton"></param>
		/// <param name="_buttonColor"></param>
		/// <param name="_textColor"></param>
		/// <returns>TSharedRef<SButton></returns>
		static TSharedRef<SButton> CreateButton(FOnClicked _eventOnClick, FText _textButton = FText(), FText _tooltipTextButton = FText(), FLinearColor _buttonColor = FLinearColor::White, FLinearColor _textColor = FLinearColor::Black);


		/// <summary>
		/// Create Button with lambda callback event
		/// </summary>
		/// <param name="_lambdaEventOnClick"></param>
		/// <param name="_textButton"></param>
		/// <param name="_tooltipTextButton"></param>
		/// <param name="_buttonColor"></param>
		/// <param name="_textColor"></param>
		/// <returns>TSharedRef<SButton></returns>
		static TSharedRef<SButton> CreateButton_Lambda(TFunction<FReply()> _lambdaEventOnClick, FText _textButton = FText(), FText _tooltipTextButton = FText(), FLinearColor _buttonColor = FLinearColor::White, FLinearColor _textColor = FLinearColor::Black);

		/// <summary>
		/// Create button with dynamic texts
		/// </summary>
		/// <param name="_eventOnClick"></param>
		/// <param name="_lambdaTextButton"></param>
		/// <param name="_lambdaTooltipTextButton"></param>
		/// <param name="_buttonColor"></param>
		/// <param name="_textColor"></param>
		/// <returns>TSharedRef<SButton></returns>
		static TSharedRef<SButton> CreateButton_DynamicText(FOnClicked _eventOnClick, TFunction<FText()> _lambdaTextButton, TFunction<FText()>  _lambdaTooltipTextButton, FLinearColor _buttonColor = FLinearColor::White, FLinearColor _textColor = FLinearColor::Black);

		/// <summary>
		/// Create Button with Dynamic Texts and Dynamic Colors
		/// </summary>
		/// <param name="_lambdaEventOnClick"></param>
		/// <param name="_lambdaTextButton"></param>
		/// <param name="_lambdaTooltipTextButton"></param>
		/// <param name="_LambdaButtonColor"></param>
		/// <param name="_lambdaTextColor"></param>
		/// <returns>TSharedRef<SButton></returns>
		static TSharedRef<SButton> CreateButton_AllDynamic(TFunction<FReply()> _lambdaEventOnClick, TFunction<FText()> _lambdaTextButton, TFunction<FText()> _lambdaTooltipTextButton, TFunction<FSlateColor()> _LambdaButtonColor, TFunction<FSlateColor()> _lambdaTextColor);
	};
}