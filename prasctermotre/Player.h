#pragma once
#include "gameobject.h"


class Player : public Gameobject
{
public:
	float delay, delay2, rof, rof2;
	int health;

	Player(float x, float y)
		:Gameobject(x, y, 35),
		delay(0), delay2(0), rof(.5f), rof2(10.f), health(3)
	{
		sprite = spritePlayer;
		speed = 180;
	}
	void onUpdate();
	void onCollision(Gameobject & o);
	void onInactive();
};