#pragma once

#include "CoreMinimal.h"

namespace EditoolsUE4
{
	
	class EditoolsUIComponents
	{
	public:

		static TSharedRef<SButton> CreateButton(FOnClicked _eventOnClick, FText _textButton, FText _tooltipTextButton);

		
		static TSharedRef<STextBlock>CreateTextBlock(FText _text);
	};

	
	

}
