#pragma once
#include "stdafx.h"
#include "Wall.h"

class RightWall : virtual public Wall
{
public:

	// Constructor
	RightWall(Parameters&);

	int Collision(Ball & theBall);

private:

	// int color;

};
