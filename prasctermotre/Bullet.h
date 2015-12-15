#pragma once
#include "gameobject.h"
#include <cmath>

class Bullet : public Gameobject
{
public:

	float lifespan;
	Bullet(float x, float y, float a_speed)
		:Gameobject(x, y, 12), lifespan(3.f)
	{
		speed = a_speed;
		if (speed > 0)
			color = CYAN;
		else color = ORAGNE;
		velocity.y = speed;

	}
	void onUpdate()
	{
		lifespan -= sfw::getDeltaTime();
		if (lifespan < 0) active = false;
	}


};