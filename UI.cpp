#include "UI.h"

UI::UI()
{
	//creating and storing UI elements
	//UIElement *uielement = new UIElement(x*60, 50, 50, x);
	//uielements.push_back(uielement);

	//DeathScreen *deathscreen = new DeathScreen();
/*	uielements.push_back(deathscreen);
	uielements.push_back(options);*/

	cursorX = 0;
	cursorY = 0;

	settingsX = 0;
	optionsX = 0;

	settingsYcursormax = 0;
	optionsYcursormax = 2;

	settingsboundX = 180;
	optionsboundX = 200;


}
void UI::UIUpdate(bool keys[], float keytimer[], int GameState)
{

	if (keys[LEFT] && keytimer[LEFT] == 0.0f)//if the left key is pressed
		cursorX--;
	if (keys[RIGHT] && keytimer[RIGHT] == 0.0f)//if the right key is pressed
		cursorX++;
	if (keys[UP] && keytimer[UP] == 0.0f)//if the up key is pressed
		cursorX = 0, cursorY++;
	if (keys[DOWN] && keytimer[DOWN] == 0.0f)//if the down key is pressed
		cursorX = 0, cursorY--;

	if (keys[ESCAPE] && keytimer[ESCAPE] == 0.0f && UIState[OPTIONS] == OFF && UIState[SETTINGS] == OFF)//go to options menu
	{
		UIState[OPTIONS] = ACTIVATING;
		cursorX = 0;//resetting input position
		cursorY = 0;
	}
	else if (keys[ESCAPE] && keytimer[ESCAPE] == 0.0f && UIState[OPTIONS] == ON && UIState[SETTINGS] == ON)//go back to options menu (if on settings menu)
	{
		UIState[SETTINGS] = DEACTIVATING;
		cursorX = 0;//resetting input position
		cursorY = 0;
	}
	else if (keys[ESCAPE] && keytimer[ESCAPE] == 0.0f && UIState[OPTIONS] == ON && UIState[SETTINGS] == OFF)//exiting options menu
	{
		UIState[OPTIONS] = DEACTIVATING;
		cursorX = 0;//resetting input position
		cursorY = 0;
	}

	if (UIState[OPTIONS] == ON && UIState[SETTINGS] == OFF)//if in options menu
	{
		if (cursorY >  optionsYcursormax)//looping cursor
			cursorY = 0;
		else if (cursorY < 0)
			cursorY =  optionsYcursormax;

		if (keys[ENTER] && keytimer[ENTER] == 0.0f) {//if the enter key is pressed
			switch (cursorY)
			{
			case 0://QUIT
				break;
			case 1://RESTART
				break;
			case 2://SETTINGS
				break;
			}
		}

	}
	else if (UIState[SETTINGS] == ON)//if in settings menu
	{
		if (cursorY >  settingsYcursormax)//looping cursor
			cursorY = 0;
		else if (cursorY < 0)
			cursorY =  settingsYcursormax;

		if (keys[ENTER] && keytimer[ENTER] == 0.0f) {//if the enter key is pressed
			switch (cursorY)
			{
			case 0://VOLUME
				break;
			}
		}
	}

	//UI activation/deactivation position handling:
	if (UIState[SETTINGS] == ACTIVATING)
	{
		if (settingsX >= settingsboundX)
			UIState[SETTINGS] = ON;
		else
			settingsX++;
	}
	else if (UIState[SETTINGS] == DEACTIVATING)
	{
		if (settingsX+settingsboundX <= 0)
			UIState[SETTINGS] = OFF;
		else
			settingsX--;
	}

	if (UIState[OPTIONS] == ACTIVATING)
	{
		if (optionsX >= optionsboundX)
			UIState[OPTIONS] = ON;
		else
			optionsX++;
	}
	else if (UIState[OPTIONS] == DEACTIVATING)
	{
		if (optionsX + optionsboundX <= 0)
			UIState[OPTIONS] = OFF;
		else
			optionsX--;
	}

}

void UI::UIRender()
{
	//for (iter = uielements.begin(); iter != uielements.end(); ++iter)
	//{
	//	(*iter)->Render();
	//}
	al_draw_filled_rectangle(0, 0, optionsX, SCREENH, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(0, 0, settingsX, SCREENH, al_map_rgb(0, 255, 0));
}