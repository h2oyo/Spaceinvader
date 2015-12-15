#pragma once
#include "vec2.h"
#include "sfwdraw.h"
#include "declcom.h"
class Gameobject
{
public:
	 static GameState *gs;

	vec2 position, velocity;
	float radius;
	unsigned color;
	unsigned sprite;
	float speed;
	bool active;

	Gameobject(float x, float y, float radius)
		: position({ x,y }), speed(0),
		velocity({ 0,0 }), radius(radius),active(true),
		color(CYAN),sprite(spriteParticle)
	{}




	void update();
	void draw();


	void setInactive()
	{
		if (!active)return;
		active = false;
		onInactive();
	}
	virtual void onInactive() {}

	virtual void onUpdate() {}
	virtual void onDraw() {}
	virtual void onCollision(Gameobject &o) {}

};

void collides(Gameobject &a, Gameobject &b);