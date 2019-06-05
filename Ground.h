#pragma once
#include "CollidableObject.h"

class Ground : public CollidableObject
{
private:
	float startX, startY, endX, endY;
public:
	Ground(float startX, float startY, float endX, float endY);
	void Render();
};