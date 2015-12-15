#pragma once
#include "gameobject.h"

class Enemy : public Gameobject
{
public :
	float delay, rof;
	Enemy(float x, float y) : Gameobject(x, y, 35),
		delay(0), rof(1.2f)
	{
		sprite = spriteEnemy;
		speed = 50;
		velocity.y = -speed;
	}
	void onCollision(Gameobject &o);

	void onInactive();

	void onUpdate();
};