#include "gameobject.h"
#include "sfwdraw.h"

GameState *Gameobject::gs;

void Gameobject::update()
{
	if (!active) return;
	position = integrate(position, velocity, sfw::getDeltaTime());

	onUpdate();
}

void Gameobject::draw()
{
	if (!active) return;
	sfw::drawTexture(sprite, position.x, position.y, radius * 2, radius * 2, 0, true, 0, color);
	//sfw::drawCircle(position.x, position.y, radius,12,color);
	onDraw();
}

void collides(Gameobject &a, Gameobject &b)
{
	if(a.active && b.active)
	if (circleOverlap(a.position, a.radius, b.position, b.radius))
	{
		a.onCollision(b);
		b.onCollision(a);
	}
}