#include "Ground.h"

Ground::Ground(float startX, float startY, float endX, float endY)
{
	Ground::startX = startX;
	Ground::startY = startY;

	Ground::endX = endX;
	Ground::endY = endY;

	//Init(startX, startY);
}
void Ground::Render()
{
	if ((SCREENH - startY) <= (SCREENH - endY))//if line is ascending
	{
		al_draw_filled_triangle(startX, startY, endX, startY, endX, endY, al_map_rgb(255, 255, 255));
		al_draw_filled_rectangle(startX, startY, SCREENW, SCREENH, al_map_rgb(255, 255, 255));
	}
	else if ((SCREENH - startY) > (SCREENH - endY))//if line is descending
	{

		al_draw_filled_triangle(startX, startY, startX, endY, endX, endY, al_map_rgb(255, 255, 255));
		al_draw_filled_rectangle(startX, endY, SCREENW, SCREENH, al_map_rgb(255, 0, 255));
	}
}