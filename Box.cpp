#include "Box.h"

Box::Box(float x, float y, int boundX, int boundY)
{
	CollidableObject::Init(x,y,0, 0, 0, 0, 0, 0, boundX,boundY, true, BOX);	

	//accY = 5;
	//dirY = 1;

	//color = al_map_rgb(255, 255, 255);
}

void Box::Update()
{
	//accY -= 0.1f;
	Object::Update();
}

void Box::Render()
{
	al_draw_filled_rectangle(x, y, x + boundX, y + boundY, al_map_rgb(255, 255, 255));// color);
}

void Box::Collided(int ObjectID)
{
	if (ObjectID == GROUND)
		cout<<"collision"<<endl;//color = al_map_rgb(255, 0, 0);
}