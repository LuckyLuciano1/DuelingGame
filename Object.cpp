#include "Object.h"

Object::Object() 
{
	x = 0;
	y = 0;

	velX = 0;
	velY = 0;

	accX = 0;
	accY = 0;

	dirX = 0;
	dirY = 0;

	alive = true;
	ID = NONE;
}

void Object::Init(float x, float y, float velX, float velY, float accX, float accY, int dirX, int dirY, int ID)
{
	Object::x = x;
	Object::y = y;

	Object::velX = velX;
	Object::velY = velY;

	Object::accX = accX;
	Object::accY = accY;

	Object::dirX = dirX;
	Object::dirY = dirY;

	Object::ID = ID;
}
void Object::Update()
{
	velX += accX * dirX;
	velY += accY * dirY;

	x += velX * dirX;
	y += velY * dirY;

	//making sure velocity and acceleration are never zero
	if (accX < 0)
		accX = 0;
	if (accY < 0)
		accY = 0;
	if (velX < 0)
		velX = 0;
	if (velY < 0)
		velY = 0;
}
void Object::Render()
{}