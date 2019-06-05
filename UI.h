#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <list>
#include <iostream>
using namespace std;

#include "Globals.h"
//#include "UIElement.h"
//
//#include "DeathScreen.h"
//#include "Options.h"

class UI
{
public:
	UI();
	void UIUpdate(bool keys[], float keytimer[], int GameState);
	void UIRender();
	
private:
	enum UISTATE { OFF, ON, ACTIVATING, DEACTIVATING };//status of uielements
	//bool UIElement[4] = { false, false, false, true };//what UI elements are currently active
	int UIState[4] = {OFF, OFF, OFF, OFF};//state of UI elements 

	int cursorX;
	int cursorY;

	int settingsYcursormax;
	int optionsYcursormax;

	int settingsX;
	int optionsX;

	float settingsboundX;
	float optionsboundX;
};