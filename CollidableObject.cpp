#include "CollidableObject.h"

void CollidableObject::Init(float x, float y, float velX, float velY, float accX, float accY, int dirX, int dirY, int boundX, int boundY, bool collidable, int ID)
{
	//bounding and collidability is specific to collidable objects
	CollidableObject::collidable = collidable;
	CollidableObject::boundX = boundX;
	CollidableObject::boundY = boundY;

	//the rest is initialized with standard Object Init().
	Object::Init(x, y, velX, velY, accX, accY, dirX, dirY, ID);
}

bool CollidableObject::CheckCollisions(CollidableObject *otherObject)
{
	float oX = otherObject->x;
	float oY = otherObject->y;

	int obX = otherObject->boundX;
	int obY = otherObject->boundY;

	if (x + boundX > oX - obX &&
		x - boundX < oX + obX &&
		y + boundY > oY - obY &&
		y - boundY < oY + obY)
		return true;
	else
		return false;
}
void CollidableObject::Collided(int ObjectID) {}
bool CollidableObject::Collidable() { return alive && collidable; }//checking function for if collision should be checked