#pragma once

#include "CoreMinimal.h"

#include "Widgets/Layout/SScrollBox.h"

namespace EditoolsUE4
{
	class EditoolsLayout
	{
	public:
		static void CreateScrollBox(EVerticalAlignment _vAlign, EHorizontalAlignment _hAlign, float _uniformPadding);
	};

}
