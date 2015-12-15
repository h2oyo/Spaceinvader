#pragma once

struct vec2
{
	float x, y;

};

float distance(vec2 a, vec2 b);
bool circleOverlap(vec2 pos1, float rad1,
	vec2 pos2, float rad2);

vec2 operator+ (vec2 a, vec2 b);
vec2 operator- (vec2 a, vec2 b);
vec2 operator* (vec2 a, float b);
vec2 operator/ (vec2 a, float b);

vec2 integrate(vec2 pos, vec2 vel, float dt);

float randRange(float min, float max);


// alpha is value between 0 and 1
float lerp(float start, float end, float alpha);