#include "Level.h"

Level::Level()
{
	Box *box1 = new Box(375, 375, 50, 50);
	objects.push_back(box1);
	collidableobjects.push_back(box1);

	float increment = SCREENW / 4.0f;
	for (float x = 0.0f; x < SCREENW; x += increment)
	{
		Ground *ground = new Ground(x, SCREENH - (10 * sqrt(x)), (x + increment), SCREENH - (10 * sqrt(x + increment)));
		objects.push_back(ground);
		collidableobjects.push_back(ground);

	}
}

void Level::LevelUpdate()
{
	//updating objects
	for (iter = objects.begin(); iter != objects.end(); ++iter)
		(*iter)->Update();

	//collisions - checking each collidable object against all other collidable objects
	for (citer = collidableobjects.begin(); citer != collidableobjects.end(); ++citer)
	{
		if (!(*citer)->Collidable()) continue;

		for (citer2 = citer; citer2 != collidableobjects.end(); ++citer2)
		{
			if (!(*citer2)->Collidable()) continue;

			if ((*citer)->CheckCollisions((*citer2)))
			{
				(*citer)->Collided((*citer2)->GetID());
				(*citer2)->Collided((*citer)->GetID());
			}
		}
	}

	//cull the dead
	for (iter = objects.begin(); iter != objects.end(); )
	{
		if (!(*iter)->GetAlive())
		{
			delete (*iter);
			iter = objects.erase(iter);
		}
		else
			iter++;
	}
	for (citer = collidableobjects.begin(); citer != collidableobjects.end(); )
	{
		if (!(*citer)->GetAlive())
		{
			delete (*citer);
			citer = collidableobjects.erase(citer);
		}
		else
			citer++;
	}
}
void Level::LevelRender()
{
	//rendering objects
	for (iter = objects.begin(); iter != objects.end(); ++iter)
		(*iter)->Render();
}