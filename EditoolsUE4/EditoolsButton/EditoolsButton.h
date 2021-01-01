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
		/// Method to create button with minimum parameters
		/// Exemple usage : EditoolsUE4::EditoolsButton::CreateButton(FOnClicked::CreateRaw(this, &MyClass::MyCallback), FText::FromString("MyText"), FText::FromString("MyTooltipText"))
		/// </summary>
		/// <param name="_eventOnClick"></param>
		/// <param name="_textButton"></param>
		/// <param name="_tooltipTextButton"></param>
		/// <returns></returns>
		static TSharedRef<SButton> CreateButton(FOnClicked _eventOnClick, FText _textButton = FText(), FText _tooltipTextButton = FText());


		


		/// <summary>
		/// Create Button with Color Options
		/// </summary>
		/// <param name="_eventOnClick"></param>
		/// <param name="_textButton"></param>
		/// <param name="_tooltipTextButton"></param>
		/// <param name="_buttonColor"></param>
		/// <param name="_textColor"></param>
		/// <returns></returns>
		static TSharedRef<SButton> CreateButtonWithColor(FOnClicked _eventOnClick, FText _textButton = FText(), FText _tooltipTextButton = FText(), FLinearColor _buttonColor = FLinearColor::White, FLinearColor _textColor = FLinearColor::Black);

	};
}