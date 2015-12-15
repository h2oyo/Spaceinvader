#include "vec2.h"
#include <cmath>
#include <ctime>




float lerp(float start, float end, float alpha)
{
	return start + alpha*(end - start);

}


float randRange(float min, float max)
{

	float alpha = rand()/(RAND_MAX*1.f);




	return min + alpha*(max -min);

}


float distance(vec2 a, vec2 b)
{
	float dx = a.x - b.x;
	float dy = a.y - b.y;

	return sqrt(dx*dx + dy*dy);
}

bool circleOverlap(vec2 pos1, float rad1, vec2 pos2, float rad2)
{
	float d = distance(pos1, pos2);
	float r = rad1 + rad2;
	return d < r;

}

vec2 operator+ (vec2 a, vec2 b)
{
	vec2 retval;
	retval.x = a.x + b.x;
	retval.y = a.y + b.y;
	return retval;
}
vec2 operator- (vec2 a, vec2 b)
{
	vec2 retval;
	retval.x = a.x - b.x;
	retval.y = a.y - b.y;
	return retval;

}
vec2 operator* (vec2 a, float b)
{
	vec2 retval;
	retval.x = a.x *b;
	retval.y = a.y *b;
	return retval;
}
vec2 operator/ (vec2 a, float b)
{
	vec2 retval;
	retval.x = a.x / b;
	retval.y = a.y / b;
	return retval;
}
vec2 integrate(vec2 pos, vec2 vel, float dt)
{

	return pos + vel *dt;
}