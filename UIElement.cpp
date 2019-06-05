#include "UIElement.h"

UIElement::UIElement() {//begins inactive, away from screen.
	x = 0;
	y = 0;

	boundX = 0;
	boundY = 0;

	state = OFF;
	ID = 0;
}

void UIElement::Init(float x, float y, int boundX, int boundY, int ID, ALLEGRO_BITMAP *overlay) {//begins inactive, away from screen.
	UIElement::x = x;
	UIElement::y = y;

	UIElement::boundX = boundX;
	UIElement::boundY = boundY;
	UIElement::ID = ID;
	UIElement::overlay = overlay;
}

void UIElement::Update() {

}

void UIElement::Render() {
	if (state != OFF)
		al_draw_bitmap(overlay, x, y, 0);
}