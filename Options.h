#pragma once
#include "UIElement.h"

class Options : public UIElement
{
public:
	Options();
	void Update(int optionsY);
	void Render();
};