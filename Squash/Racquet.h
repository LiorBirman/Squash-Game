#pragma once
#include "stdafx.h"
#include "InvisibleWall.h"

class Racquet : virtual public InvisibleWall
{
public:

	// Constructor
	Racquet(Parameters&);

	// Getters
	double getCenterOfRacquet() { return ((x1 + x2) / 2); }

	void MoveLeftRight(double);
};

