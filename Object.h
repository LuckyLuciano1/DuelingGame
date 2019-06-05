#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>

#include "Globals.h"
using namespace std;

class Object {//covers anything rendered in game (short term non colliding objects are effects subclass), excluding UI, background and basic ground image

protected://can be accessed by child members
	bool alive;

	//movement variables
	float x, y;
	float velX, velY;
	float accX, accY;
	int dirX, dirY;

	int ID;

public://can be accessed by anything
	Object();
	
	void virtual Init(float x, float y, float velX, float velY, float accX, float accY, int dirX, int dirY, int ID);
	void virtual Update();//'virtual' function essentially makes the code run the derived classes Update/Render functions if available, instead of the Object classes Update/Render.
	void virtual Render();//'virtual' due to objects requiring unique rendering conditions

	int GetID() { return ID; }
	bool GetAlive() { return alive; }


};