#include "Player.h"
#include "sfwdraw.h"
#include "declcom.h"
#include "GameState.h"


void Player :: onUpdate()
{

	

	velocity = { 0,0 };
	delay += sfw::getDeltaTime();
	delay2 += sfw::getDeltaTime();

 	if (sfw::getKey(' ')&& delay > rof)
	{
		delay = 0;
		gs->spawnBullet(position.x, position.y, 300);
	}

	if (sfw::getKey('Z') && delay2 > rof2 && gs->score > 25)
	{
		delay2 = 0;
		gs->spawnBullet(position.x, position.y, 300);
		gs->spawnBullet(position.x+10, position.y, 300);
		gs->spawnBullet(position.x+30, position.y, 300);
		gs->spawnBullet(position.x+50, position.y, 300);
		gs->spawnBullet(position.x+70, position.y, 300);
		gs->spawnBullet(position.x + 90, position.y, 300);
		gs->spawnBullet(position.x + 110, position.y, 300);
		gs->spawnBullet(position.x + 130, position.y, 300);
		gs->spawnBullet(position.x + 150, position.y, 300);
		gs->spawnBullet(position.x - 10, position.y, 300);
		gs->spawnBullet(position.x - 30, position.y, 300);
		gs->spawnBullet(position.x - 50, position.y, 300);
		gs->spawnBullet(position.x - 70, position.y, 300);
		gs->spawnBullet(position.x - 90, position.y, 300);
		gs->spawnBullet(position.x - 110, position.y, 300);
		gs->spawnBullet(position.x - 130, position.y, 300);
		gs->spawnBullet(position.x - 150, position.y, 300);
	
	}
	if (sfw::getKey('A'))
	{
		velocity.x = -speed;
	}
	if (sfw::getKey('D'))
	{
		velocity.x = speed;
	}

	if (position.x - radius < BOUNDS_LEFT)
	{
		position.x = BOUNDS_LEFT + radius;

	}
	if (position.x + radius > BOUNDS_RIGHT)
	{
		position.x = BOUNDS_RIGHT - radius;

	}

}

void Player::onCollision(Gameobject &o)
{
	if (o.velocity.y < 0)
	{
		health--;
	
		o.setInactive();
		switch (health)
		{
		case 2: color = BLUE; break;
		case 1: color = RED; break;
		case 0: setInactive(); break;
		}
	}
}

void Player::onInactive()
{
	gs->spawnParticle(position.x, position.y, 0, 600, .2f, RED);
	gs->spawnParticle(position.x, position.y, 3, 15, .4f, YELLOW);
	gs->spawnParticle(position.x, position.y, 12, 0, .3f, MAGENTA);
	gs->spawnParticle(position.x, position.y, 15, 24, .6f, GREEN);
}

