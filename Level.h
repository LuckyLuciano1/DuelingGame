#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <list>
#include <iostream>
using namespace std;

#include "Object.h"
#include "CollidableObject.h"
#include "Box.h"
#include "Ground.h"

class Level
{
private:

	std::list<Object *> objects;
	std::list<Object *>::iterator iter;

	std::list<CollidableObject *> collidableobjects;
	std::list<CollidableObject *>::iterator citer;
	std::list<CollidableObject *>::iterator citer2;

public:
	Level();

	void LevelUpdate();
	void LevelRender();

};