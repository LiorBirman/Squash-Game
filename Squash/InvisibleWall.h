#pragma once
#include "stdafx.h"
#include "Wall.h"

class InvisibleWall :virtual public Wall
{
public:

	InvisibleWall();

	// Constructor
	InvisibleWall(Parameters&);

	int Collision(Ball&);
	int getcolor() { return color; }

private:

	int color; // Invisible

};
