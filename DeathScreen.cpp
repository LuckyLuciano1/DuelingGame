#include "DeathScreen.h"

DeathScreen::DeathScreen()
{
	UIElement::Init(0, 0, SCREENW, SCREENH, DEATHSCREEN, al_load_bitmap("DeathScreen.png"));

}

void DeathScreen::Update()
{
	if (state == ACTIVATING) {
		if (IsFullyOnscreen()) {//if it no longer needs to activate, dont activate
			state = ON;
		}
		else {//continue activating
			x += 1.0f;
		}
	}
	else if (state == DEACTIVATING) {
		if (IsFullyOffscreen()) {
			state = OFF;
		}
		else {
			x -= 1.0f;
		}
	}
}

void DeathScreen::Render()
{
	if(state != OFF)
		al_draw_bitmap(overlay, x, y, 0);
}