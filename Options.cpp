#include "Options.h"

Options::Options()
{
	UIElement::Init(0, 0, SCREENW, SCREENH, OPTIONS, al_load_bitmap("Options.png"));
}
void Options::Update(int optionsY)
{

}
void Options::Render()
{
	al_draw_rectangle(x, y, x + boundX, y + boundY, al_map_rgb(255, 255, 255), 1);
}