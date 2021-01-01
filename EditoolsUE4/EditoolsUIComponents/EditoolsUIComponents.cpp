#include "EditoolsUIComponents.h"


TSharedRef<STextBlock> EditoolsUE4::EditoolsUIComponents::CreateTextBlock(FText _text)
{
	return SNew(STextBlock)
	.Text(_text);
}
