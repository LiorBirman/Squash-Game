#pragma once
#include "stdafx.h"
#include "Wall.h"

class UpperWall : virtual public Wall
{
public:
	// Constructor
	UpperWall(Parameters&);

	int Collision(Ball&);

private:
protected:
	// int color;
};