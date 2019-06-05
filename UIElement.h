#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#include "Globals.h"

class UIElement
{
protected:
	float x, y;
	int boundX, boundY;
	int state;

	enum UISTATE { ACTIVATING, ON, DEACTIVATING, OFF };//status of uielements

	ALLEGRO_BITMAP *overlay;

public:
	UIElement();
	void virtual Init(float x, float y, int boundX, int boundY, int ID, ALLEGRO_BITMAP *overlay);

	int GetState() { return state; }
	void SetState(int input) { state = input; }

	void virtual Update();
	void virtual Render();

	int ID;

protected:

	bool IsFullyOffscreen() {
		if (x + boundX < 0) return true;
		else if (x > SCREENW) return true;
		else if (y + boundY < 0) return true;
		else if (y > SCREENH) return true;
		else return false;
	}
	bool IsFullyOnscreen() {
		if (x >= 0 &&
			x + boundX <= SCREENW &&
			y >= 0 &&
			y + boundY <= SCREENH) return true;
		else return false;
	}
};