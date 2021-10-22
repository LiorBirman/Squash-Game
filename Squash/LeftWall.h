#pragma once
#include "stdafx.h"
#include "Wall.h"

class LeftWall : virtual public Wall
{
public:

	// Constructor
	LeftWall(Parameters&);

	int Collision(Ball&);

private:

	// int color;

};

