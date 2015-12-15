#pragma once
#include "gameobject.h"
// In game state
	//vector of particles, spawn particle function
	//we have to update/ draw particles
//anywhere esle now we can call spawnParticle
class Particle : public Gameobject 

{
public:
	float startRadius,endRadius;
	float lifespan, lifetime;

	Particle(float x, float y, float a_startRadius,
		float a_endRadius, float a_lifetime,
		unsigned a_color)


		:Gameobject(x, y, a_startRadius), 
		endRadius(a_endRadius), startRadius(a_startRadius),
		lifespan(0), lifetime(a_lifetime)
	{
	
		color = a_color;
	
	
	}


	void onUpdate()
	{
		radius = lerp(startRadius, endRadius, lifespan / lifetime);
		lifespan += sfw::getDeltaTime();
	
		if (lifespan > lifetime) active = false;
	}
};