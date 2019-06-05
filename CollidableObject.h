#pragma once
#include "Object.h"

class CollidableObject : public Object
{
private:

protected:
	bool collidable;
	int boundX;
	int boundY;
public:
	void Init(float x, float y, float velX, float velY, float accX, float accY, int dirX, int dirY, int boundX, int boundY, bool collidable, int ID);

	bool CheckCollisions(CollidableObject *otherObject);
	void virtual Collided(int ObjectID);
	bool Collidable();
};