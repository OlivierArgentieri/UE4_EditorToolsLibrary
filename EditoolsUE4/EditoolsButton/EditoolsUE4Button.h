#pragma once

#include "CoreMinimal.h"

namespace EditoolsUE4
{
	
	class EditoolsButton
	{
	public:

		static TSharedRef<SButton> CreateButton(FOnClicked _eventOnClick, const char* Str, const char* Text);
	};

	
	

}
