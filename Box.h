#pragma once
#include "CollidableObject.h"

class Box : public CollidableObject
{

private:
	//ALLEGRO_COLOR color = al_map_rgb(255, 255, 255);
public:
	Box(float x, float y, int boundX, int boundY);

	void Render();
	void Update();

	void Collided(int ObjectID);
};