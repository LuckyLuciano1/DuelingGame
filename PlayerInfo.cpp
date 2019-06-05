#include "PlayerInfo.h"

PlayerInfo::PlayerInfo()
{
	UIElement::Init(-40.0, 0.0, 40, 20, PLAYERINFO, al_load_bitmap("PlayerInfo.png"));
}
void PlayerInfo::Update()
{
	if (state == ACTIVATING) {
		if (IsFullyOnscreen()) {//if it no longer needs to activate, dont activate
			state = ON;
		}
		else {
			x += 1.0f;//otherwise, move right towards screen
		}
	}
	else if (state == DEACTIVATING) {
		if (IsFullyOffscreen()) {
			state = OFF;
		}
		else {
			x -= 1.0f;//otherwise, move left away from screen
		}
	}
}
void PlayerInfo::Render()
{
	al_draw_bitmap(overlay, x, y, 0);
}