#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <iostream>

#include "Globals.h"
#include "Level.h"
#include "UI.h"

using namespace std;

class Engine
{
private:

	bool render;
	bool running;

	int GameState;//where the player is in the game
	
	int frames;
	float engineTime;
	int engineFPS;

	float FPS;

	bool keys[14] = { false, false, false, false, false, false, false, false, false, false, false, false, false, false };
	float keytimer[14] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };//times how long a key is being pressed for

	ALLEGRO_MOUSE_STATE state;
	float lmouseup = 0.0f;//times how long mouse buttons have been released for (for sake of double clicking) 
	float rmouseup = 0.0f;
	float mouseX = 0.0f;//position of mouse
	float mouseY = 0.0f;

	int settingsX;
	int settingsY;

	int optionsY;
	int startY;
	int deathY;


	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *font18;

	Level level;
	UI UI;

public:
	Engine(float FPS);
	void GameLoop();
	void Close();

private:
	void GameUpdate();
	void GameRender();
	void GameEventManager(ALLEGRO_EVENT ev);

	void EventKeyDown(ALLEGRO_EVENT ev);
	void EventKeyUp(ALLEGRO_EVENT ev);

	void MenuInput();
};
