#pragma once
// interface

class BaseState
{
public:

	virtual void update() = 0;
	virtual void draw() = 0;

};