#include "Enemy.h"
#include "GameState.h"
#include <iostream>

void Enemy::onUpdate()
{
	delay += sfw::getDeltaTime();
	if (delay > rof)
	{
		delay = 0;
		gs->spawnBullet(position.x, position.y, -300);
	}
	if (position.y < BOUNDS_BOTTOM)
	{ 
		active = false;
	}

}
void Enemy::onCollision(Gameobject &o)
{
	if (o.velocity.y > 0)
	{
		setInactive();
		o.setInactive();
		gs->score++;
		std::cout << gs->score << std::endl;
	}
}

void Enemy::onInactive()
{
	gs->spawnParticle(position.x, position.y, 0, 100, .1f, YELLOW);
	gs->spawnParticle(position.x, position.y, 3, 15, .4f, BLUE);
	gs->spawnParticle(position.x, position.y, 12, 0, .3f, RED);
}